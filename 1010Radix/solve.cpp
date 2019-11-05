#include<iostream>
#include<string>
using namespace std;

long long int parseDecimal(string const& src, const long long int radix)
{
    long long int pow = 1;
    long long int result = 0;
    for(int i=src.length()-1; i >= 0; --i)
    {
        char c = src[i];
        if('0' <= c && c <= '9')
        {
            c -= '0';
        }
        else if('a' <= c && c <= 'z')
        {
            c = c - 'a' + 10;
        }
        if(c >= radix)
        {
            // 出现了比进制大的位
            return 0;
        }
        result += pow * c;
        pow *= radix;
        if(result < 0)
        {
            return -1;
        }
    }
    return result;
}

int main()
{
    string N1,N2;
    long long int tag=0, radix=0;
    cin >> N1 >> N2 >> tag >> radix;
    if(tag == 2)
    {
        // 让radix固定为N1的进制
        string temp = N1;
        N1 = N2;
        N2 = temp;
    }
    const long long int n1=parseDecimal(N1, radix);
    long long upper = n1+1;
    long long lower = 2;
    while(lower <= upper)
    {
        long long i = (lower + upper) / 2;
        long long int n2 = parseDecimal(N2, i);
        if(n1 == n2)
        {
            cout << i;
            return 0;
        }
        if(n1 < n2 || n2 < 0)
        {
            upper = i - 1;
        }
        else
        {
            lower = i + 1;
        }
        
    }
    cout << "Impossible";
    return 0;
}