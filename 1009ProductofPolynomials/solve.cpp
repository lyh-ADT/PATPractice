#include<iostream>
#include<map>
#include<iomanip>
using namespace std;

int main()
{
    map<int, double> result_poly;
    map<int, double> first_poly;
    int K=0;
    cin >> K;
    for(int _=0; _ < K; ++_)
    {
        int n = 0;
        double a = 0;
        cin >> n >> a;
        first_poly[n] = a;
    }
    cin >> K;
    for(int _=0; _ < K; ++_)
    {
        int n = 0;
        double a = 0;
        cin >> n >> a;
        for(auto i=first_poly.begin(); i != first_poly.end(); ++i)
        {
            result_poly[i->first+n] += i->second * a;
        }
    }
    
    int item_count = 0;
    for(auto i=result_poly.begin(); i != result_poly.end(); ++i)
    {
        if(i->second != 0)
        {
            item_count += 1;
        }
    }
    cout << item_count;
    if(item_count <= 0)
    {
        return 0;
    }
    for(auto i=--result_poly.end(); i != result_poly.begin(); --i)
    {
        if(i->second != 0)
            cout << " " << i->first << " " << setiosflags(ios::fixed) << setprecision(1) << i->second;
    }
    if(result_poly.begin()->second != 0)
        cout << " " << result_poly.begin()->first << " " << setiosflags(ios::fixed) << setprecision(1) << result_poly.begin()->second;
    return 0;
}