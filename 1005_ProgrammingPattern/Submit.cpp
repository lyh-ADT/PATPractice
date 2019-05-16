#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

static const auto disable_sync=[](){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

bool compareStr(string const& a, string const& b){
    //return  a < b
    for(int i=0; i < a.size(); ++i){
        if(i >= b.size()){
            return true;
        }
        if(a[i] != b[i]){
            return a[i] < b[i];
        }
    }
    return false;
}

void findSubStr(string const& str, string const& sub, vector<int>& indexes){
    // KMP
    const int n = sub.size();
    vector<int> tb(n, 0);
    tb[0]=-1;
    for(int i=1; i < n; ++i){
        for(int t=1; t < i-1; ++t){
            if(sub.substr(0,t) == sub.substr(i-t, t)){
                tb[i]=t;
                
            }
        }
        if(sub[tb[i]] == sub[i]){
            tb[i] = tb[tb[i]];
        }
    }
    int str_index=0, sub_index=0;
    while(str_index < str.size()){
        if(sub_index != -1 && str[str_index] == sub[sub_index]){
            ++str_index;
            ++sub_index;
           
        } else {
            if(sub_index == -1){
                ++str_index;
                sub_index=0;
                continue;
            }
            sub_index = tb[sub_index];
        }
        if(sub_index == n){
            indexes.push_back(str_index-n);
            sub_index=tb[sub_index-1];
            str_index-=n-sub_index-1;
            
        }
    }
}
// abbcabc
int main(){
    int N;
    string s;
    cin >> N;
    cin.get();
    getline(cin, s);
    const int max_index = s.size()-N-1;
    vector<int> mostSubStrIndex;
    string mostSubStr;
    map<string, bool> foundSub;
    for(int i=0; i <= max_index; ++i){
        vector<int> tmpIndexes;
        string tmpString=s.substr(i,N);
        if(foundSub[tmpString]){
            continue;
        } else {
            foundSub[tmpString] = true;
        }
        findSubStr(s, tmpString, tmpIndexes);
        if(mostSubStrIndex.size() < tmpIndexes.size()){
            mostSubStrIndex = tmpIndexes;
            mostSubStr = tmpString;
        } else if(mostSubStrIndex.size() == tmpIndexes.size()){
            if(compareStr(tmpString, mostSubStr)){
                mostSubStr = tmpString;
            }
        }
    }
    cout << mostSubStr << " " << mostSubStrIndex.size();
    return 0;
}