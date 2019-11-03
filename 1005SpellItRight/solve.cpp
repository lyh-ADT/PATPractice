#include<iostream>
#include<string>
using namespace std;

const string map[10]=
{
    "zero", "one", "two", "three", "four", 
    "five", "six", "seven", "eight", "nine"
};

int main()
{
    char cur='\0';
    int result[100] = {0};
    int digits = 100;
    while(cur = cin.get())
    {
        if(cur == '\n')break;
        int num = cur - '0';
        int pos = 99;
        while(true)
        {
            int t = num + result[pos];
            result[pos] = t % 10;
            if(t >= 10)
            {
                num = 1;
                pos--;
            }
            else
            {
                break;
            }
        }
        digits = min(digits, pos);
    }
    for(int i=digits; i < 100; ++i)
    {
        cout << map[result[i]];
        if(i < 99)
        {
            cout << " ";
        }
    }
    return 0;
}