#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;


struct Game
{
    int game=0;
    int buy=0;
    double odd=0;
};
const char TITLE[3]={'W', 'T', 'L'};

int main()
{
    double info[3][3];
    for(int i=0; i < 3; ++i)
    {
        for(int j=0; j < 3; ++j)
        {
            cin >> info[i][j];
        }
    }
    vector<Game> bet;
    for(int i=0; i < 3; ++i)
    {
        Game biggest;
        for(int j=0; j < 3; ++j)
        {
            if(info[i][j] > biggest.odd)
            {
                biggest = {i, j, info[i][j]};
            }
        }
        bet.push_back(biggest);
    }

    double profit = 1;
    for(int i=0; i < 3; ++i)
    {
        cout << TITLE[bet[i].buy] << " ";
        profit *= bet[i].odd;
    }
    profit = (profit * 0.65 -1) * 2;
    cout << setiosflags(ios::fixed) << setprecision(2) << profit;
    return 0;
}