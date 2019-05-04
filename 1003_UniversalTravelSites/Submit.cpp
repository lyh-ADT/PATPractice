#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<string>
using namespace std;

int fluenceBFS(vector<vector<int>> &edges, int const& planets_n, vector<int>& flue, int st, int en){
    queue<int> Q;
    Q.push(st);
    vector<int> f(planets_n, 0);
    f[st]=0x7fffffff;
    while(!Q.empty()){
        int t = Q.front();
        Q.pop();
        if(t == en){
            break;
        }
        for(int i=0; i <planets_n; ++i){
            if(edges[t][i] !=0 && flue[i]==-1){
                flue[i] = t;
                f[i] = min(f[t], edges[t][i]);
                Q.push(i);
            }
        }
    }
    return f[en];
}

int maxFluence(vector<vector<int>>& edges, int const& planets_n, int st, int en){
    int ans = 0;
    while(true){
        vector<int> flue(planets_n, -1);
        int f=fluenceBFS(edges, planets_n, flue, st, en);
        if(f==0){
            break;
        }
        ans += f;
        int now = en;
        while(now != st && now != -1){
            int pre = flue[now];
            edges[pre][now] -= f;
            edges[now][pre] += f;
            now = pre;
        }
    }
    return ans;
}

int main(){
    string st_str, en_str;
    int n;
    cin >> st_str >> en_str>>n;
    map<string, int> namesId;
    int planets_n = 0;
    namesId[st_str] = planets_n++;
    namesId[en_str] = planets_n++;
    vector<vector<int>> edges(1010, vector<int>(1010, 0));
    for(int i=0; i < n; ++i){
        string str1, str2;
        int c;
        cin >> str1 >> str2 >> c;
        auto it1 = namesId.find(str1);
        auto it2 = namesId.find(str2);
        int t1 = 0;
        int t2 = 0;
        if(it1 == namesId.end()){
            t1 = planets_n++;
            namesId[str1] = t1;
        }
        else{
            t1 = it1->second;
        }
        if(it2 == namesId.end()){
            t2=planets_n++;
            namesId[str2]=t2;
        }
        else{
            t2 = it2->second;
        }
        edges[t1][t2] = c;
    }
    int ans = maxFluence(edges, planets_n, 0, 1);
    cout << ans;
    return 0;
}