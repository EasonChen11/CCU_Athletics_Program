//
// Created by ysche on 2022/4/15.
//
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<ll,ll> lp;
int main(){
    ll n,m,times=0;
    cin>>n>>m;
    vector<vector<lp>> link(n+1);
    for (int i = 0; i < m; ++i) {
        ll first,second,weight;
        cin>>first>>second>>weight;
        link[first].push_back({second,weight});
    }
    vector<ll> far(n+1,INF);
    far[1]=0;
    bool changed= true;
    while(changed && times++<=n-1){
        changed= false;
        for (int i = 0; i <= n; ++i) {
            for(auto x:link[i]){
                if(far[x.first]>far[i]+x.second){
                    far[x.first]=far[i]+x.second;
                    changed= true;
                }
            }
        }
    }
    if(times<=n-1)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}