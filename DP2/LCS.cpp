#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    string s,t;
    cin>>s>>t;
    vector<vector<int>> graph(s.size()+1,vector<int>(t.size()+1,0));//+空集合
    for (int i = 1; i <= s.size(); ++i) {
        for (int j = 1; j <= t.size(); ++j) {
            if(s[i-1]==t[j-1]){
                graph[i][j]+=graph[i-1][j-1]+1;
            }else{
                graph[i][j]=max(graph[i-1][j],graph[i][j-1]);
            }
        }
    }
    cout<<graph[s.size()][t.size()];
    return 0;
}