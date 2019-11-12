#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int INF = 0x7fffffff;

vector<int> findBest(const vector<int>& bikes, const vector<vector<int>>& roads, int S)
{
    vector<int> result={S};
    int need 
    while(S != 0)
    {
        int best_index = 0;
        int best = 0;
        for(int i : roads[S])
        {
            if()
        }
    }
}

int main()
{
    int C=0, N=0, S=0, M=0;
    cin >> C >> N >> S >> M;
    vector<int> bikes(N+1, 0);
    for(int i=1; i <= N; ++i)
    {
        cin >> bikes[i];
        bikes[i] -= C/2;
    }
    vector<vector<int>> roads(N+1, vector<int>(N+1, INF));
    for(int _=0; _ < M; ++_)
    {
        int x=0, y=0, cost=0;
        cin >> x >> y >> cost;
        roads[x][y] = roads[y][x] = cost;
    }

    // dijkstra
    vector<int> s = {0};
    vector<int> r;
    vector<int> min_costs(N+1, INF);
    vector<vector<int>> shortest_road(N+1);
    min_costs[0] = 0;
    for(int i=1; i <= N; ++i)r.push_back(i);
    while(!r.empty())
    {
        int min_index = 0;
        int min_cost = INF;
        for(int i : s)
        {
            for(int j : r)
            {
                if(roads[i][j] == INF) continue;
                int tmp_cost = min_costs[i] + roads[i][j];
                if(tmp_cost < min_cost)
                {
                    min_index = j;
                    min_cost = tmp_cost;
                }
            }
        }
        min_costs[min_index] = min_cost;
        for(int i : s)
        {
            if(min_costs[i] + roads[i][min_index] == min_cost)
            {
                shortest_road[min_index].push_back(i);
            }
        }
        s.push_back(min_index);
        r.erase(find(r.begin(), r.end(), min_index));
    }
    string path = "";
    int total_bike = 0;
    int stations = 0;
    
    int need = C/2*stations-total_bike;
    cout << max(need, 0) << " 0" << path << " " << (need > 0 ? 0 : -need);
    return 0;
}

/*
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1
*/