#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int get_root(const vector<int>& father, int x)
{
    int root = father[x];
    while(root != father[root]) root = father[root];
    return root;
}

void union_set(vector<int>& father, int x1, int x2)
{
    int root1 = get_root(father, x1);
    int root2 = get_root(father, x2);
    if(root1 == root2) return;
    for(int i=0; i < father.size(); ++i)
    {
        if(father[i] == root2)
        {
            father[i] = root1;
        }
    }
}

int check(const vector<vector<bool>>& briges, int destroy)
{
    const int N = briges.size();
    // 并查集
    vector<int> fathers(N, 0);
    for(int i=0; i < N; ++i)
    {
        fathers[i] = i;
    }
    for(int i=0; i < N; ++i)
    {
        if(i == destroy) continue;
        for(int j=i+1; j <= N; ++j)
        {
            if(briges[i][j] && j != destroy)
            {
                // 合并
                union_set(fathers, i, j);
            }
        }
    }
    // 计算有多少个集合
    unordered_map<int, bool> flags;
    for(int i=1; i < N; ++i)
    {
        if(i != destroy)
            flags[fathers[i]] = true;
    }
    return flags.size()-1;
}

int main()
{
    int N=0, M=0, K=0;
    cin >> N >> M >> K;
    // 邻接矩阵
    vector<vector<bool>> briges(N+1, vector<bool>(N+1, false));
    for(int _=0; _ < M; ++_)
    {
        int i=0, j=0;
        cin >> i >> j;
        briges[i][j] = true;
        briges[j][i] = true;
    }
    for(int _=0; _ < K; ++_)
    {
        int destroy = 0;
        cin >> destroy;
        cout << check(briges, destroy) << endl;
    }
    return 0;
}