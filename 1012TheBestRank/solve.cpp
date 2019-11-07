#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

struct Grade
{
    string id="";
    int score=0;
    bool operator<(const Grade& rhs)
    {
        return score < rhs.score;
    }
};

const char TITLE[4]={'A','C','M','E'};

int main()
{
    int N=0, M=0;
    cin >> N >> M;
    vector<vector<Grade>> data(4, vector<Grade>(N));
    for(int i=0; i < N; ++i)
    {
        string id;
        cin >> id;
        int average = 0;
        data[1][i].id = id;
        cin >> data[1][i].score;
        average += data[1][i].score;
        data[2][i].id = id;
        cin >> data[2][i].score;
        average += data[2][i].score;
        data[3][i].id = id;
        cin >> data[3][i].score;
        average += data[3][i].score;
        data[0][i].id = id;
        data[0][i].score = average/3. + 0.5;
    }
    unordered_map<string, vector<int>> map;
    for(int i=0; i < 4; ++i)
    {
        sort(data[i].begin(), data[i].end());
        int curRank = N;
        for(int j=N-1; j >= 0; --j)
        {
            if(j==N-1 || data[i][j+1].score != data[i][j].score)
            {
                curRank = N-j;
                map[data[i][j].id].push_back(curRank);
            }
            else
            {
                map[data[i][j].id].push_back(curRank);
            }
        }
    }
    
    for(int _=0; _ < M; ++_)
    {
        string id;
        cin >> id;
        const vector<int>& grade=map[id];
        if(grade.size() == 0)
        {
            cout << "N/A";
        }
        else
        {
            int rank=N+1;
            char subject=0;
            for(int i=0; i < 4; ++i)
            {
                if(grade[i] < rank)
                {
                    rank = grade[i];
                    subject = TITLE[i];
                }
            }
            cout << rank << " " << subject;
        }
        if(_ < M-1)
        {
            cout << endl;
        }
    }
    return 0;
}