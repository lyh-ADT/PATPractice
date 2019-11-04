#include<iostream>
using namespace std;

int main()
{
    int N=0;
    cin >> N;
    int current_floor = 0;
    int total_time = 0;
    for(int i=0; i < N; ++i)
    {
        int dst = 0;
        cin >> dst;
        if(dst < current_floor)
        {
            // 往下走
            total_time += (current_floor-dst)*4 + 5;
        }
        else
        {
            // 往上走 
            total_time += (dst-current_floor)*6 + 5;
        }
        current_floor = dst;
    }
    cout << total_time;
    return 0;
}