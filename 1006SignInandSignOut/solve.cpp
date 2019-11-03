#include<iostream>
#include<string>
using namespace std;

int main()
{
    string first_time="9";
    string unlock_id;
    string last_time="0";
    string lock_id;
    int N=0;
    cin >> N;
    for(int _=0; _ < N; ++_)
    {
        string id, signin, signout;
        cin >> id >> signin >> signout;
        if(signin < first_time)
        {
            first_time = signin;
            unlock_id = id;
        }
        if(signout > last_time)
        {
            last_time = signout;
            lock_id = id;
        }
    }
    cout << unlock_id << " " << lock_id;
    return 0;
}