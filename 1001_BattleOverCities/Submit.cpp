#include <iostream>
#include <map>
#include <vector>
using namespace std;  

static const auto disable_sync = [](){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

int N, M;
// 邻接矩阵
vector<vector<int>> cityMap;
vector<vector<bool>> connectStatusMap;

int find_set(vector<int> const &ufs, int v) {
    while (ufs[v] != v) {
        v = ufs[v];
    }
    return v;
}

int connenct_set(map<int, vector<int>> &ufsMap) {
    int cost = 0;
    for (auto i = ufsMap.begin(); i != ufsMap.end(); ++i) {
        for (auto j = i; j != ufsMap.end();) {
            if (i == j) {
                ++j;
            }
            int minCost = INT32_MAX;
            for (int a : i->second) {
                for (int b : j->second) {
                    if (cityMap[a][b] < minCost) {
                        minCost = cityMap[a][b];
                    }
                }
            }
            i->second.insert(i->second.end(), j->second.begin(),
                             j->second.end());
            j = ufsMap.erase(j);
            cost += minCost;
        }
    }
    return cost;
}

int getRepairCost(int conqueredCity) {
    vector<int> ufs(N + 1);
    map<int, vector<int>> ufsMap;
    for (int i = 1; i <= N; ++i) {
        if (i == conqueredCity)
            continue;
        ufs[i] = i;
        ufsMap[i] = {i};
    }

    for (int i = 1; i <= N; ++i) {
        if (i == conqueredCity)
            continue;
        for (int j = i + 1; j <= N; ++j) {
            if (j == conqueredCity)
                continue;
            if (connectStatusMap[i][j]) {
                int x = find_set(ufs, i);
                int y = find_set(ufs, j);
                ufs[x] = y;
                ufsMap[y].insert(ufsMap[y].end(), ufsMap[x].begin(),
                                 ufsMap[x].end());
                ufsMap.erase(x);
            }
        }
    }
    if (ufsMap.size() == 1) {
        return 0;
    }
    return connenct_set(ufsMap);
}

int main() {
    cin >> N >> M;
    cityMap.assign(N + 1, vector<int>(N + 1, INT32_MAX));
    connectStatusMap.assign(N + 1, vector<bool>(N + 1, 0));
    // 输入数据
    for (int i = 0; i < M; ++i) {
        int city1, city2, cost, status;
        cin >> city1 >> city2 >> cost >> status;
        cityMap[city1][city2] = cityMap[city2][city1] = cost;
        connectStatusMap[city1][city2] = connectStatusMap[city2][city1] =
            status;
    }
    vector<int> result;
    int maxCost = 0;
    for (int conqueredCity = 1; conqueredCity <= N; ++conqueredCity) {
        int curCost = getRepairCost(conqueredCity);
        if (curCost >= maxCost) {
            if (curCost > maxCost) {
                result.clear();
                maxCost = curCost;
            }
            result.push_back(conqueredCity);
        }
    }
    if (maxCost == 0) {
        cout << 0 << endl;
    } else {
        for (int i = 0; i < result.size(); ++i) {
            if (i == result.size() - 1) {
                cout << result[i] << endl;
                break;
            }
            cout << result[i] << " ";
        }
    }
    return 0;
}