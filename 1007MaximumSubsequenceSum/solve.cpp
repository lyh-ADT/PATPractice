#include<iostream>
using namespace std;

struct Result
{
    int sum=0;
    int i=0;
    int j=0;
    void print(){cout << sum << " " << i << " " << j;}
};

int main()
{
    int K=0;
    cin >> K;
    int array[K+1]={0};
    bool all_negative = true;
    for(int i=0; i < K; ++i)
    {
        cin >> array[i+1];
        if(array[i+1] >= 0)
        {
            all_negative = false;
        }
    }
    if(all_negative)
    {
        cout << 0 << " " << array[1] << " " << array[K];
        return 0;
    }

    int dp[K+1]={0};
    Result result;
    for(int i=1; i <= K; ++i)
    {
        dp[i-1] = 0;
        for(int j=i; j <= K; ++j)
        {
            dp[j] = dp[j-1] + array[j];
            if(dp[j] > result.sum)
            {
                result = {dp[j], array[i], array[j]};
            }
        }
    }
    result.print();
    return 0;
}