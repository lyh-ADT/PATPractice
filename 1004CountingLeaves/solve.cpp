#include<iostream>
#include<vector>
using namespace std;

void count(const vector<vector<bool>> tree, vector<int>& result, vector<int> curLevel)
{
    if(curLevel.empty())return;
    vector<int> nextLevel;
    int leave_count = 0;
    for(int father : curLevel)
    {
        bool have_child = false;
        for(int i=0; i < tree[father].size(); ++i)
        {
            if(tree[father][i])
            {
                have_child = true;
                nextLevel.push_back(i);
            }
        }
        if(!have_child)
        {
            leave_count++;
        }
    }
    result.push_back(leave_count);
    count(tree, result, nextLevel);
}
int main()
{
    int N=0, M=0;
    cin >> N;
    // if(N == 0)return 0;
    cin >> M;
    vector<vector<bool>> tree(N+1, vector<bool>(N+1, false));
    for(int i=0; i < M; ++i)
    {
        int id=0, k=0;
        cin >> id >> k;
        for(int j=0; j < k; ++j)
        {
            int child=0;
            cin >> child;
            tree[id][child] = true;
        }
    }

    vector<int> result;
    count(tree, result, vector<int>{1});

    for(int i=0; i < result.size(); ++i)
    {
        cout << result[i];
        if(i < result.size()-1)
        {
            cout << " ";
        }
    }
    return 0;
}