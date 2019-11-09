#include<iostream>
#include<string>
#include<vector>
using namespace std;

long long parseRadixReverse(int num, int radix)
{
    long long result = 0;
    while(num > 0)
    {
        int mod = num % radix;
        result = result * 10 + mod;
        num = num / radix;
    }
    return result;
}

int parseDecimal(long long num, int radix)
{
    int result = 0;
    int pow = 1;
    while (num > 0)
    {
        int x = num % 10;
        result += x * pow;
        pow *= radix;
        num /= 10;
    }
    return result;
}

int main()
{
    // 素数筛
    vector<bool> is_primes(99999+1, true);
    is_primes[0] = false;
    is_primes[1] = false;
    for(int i=2; i < 99999+1; ++i)
    {
        for(int j=2*i; is_primes[i] && j < 99999+1; j += i)
        {
            is_primes[j] = false;
        }
    }

    int N=0;
    cin >> N;
    while(N > 0)
    {
        int D = 0;
        cin >> D;
        int rnum = parseDecimal(parseRadixReverse(N, D),D);
        cout << (is_primes[N] && is_primes[rnum] ? "Yes" : "No") << endl;
        cin >> N;
    }
    
    return 0;
}