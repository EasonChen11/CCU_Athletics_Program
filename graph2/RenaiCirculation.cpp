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
    priority_queue<ll> pq;
    bool changed;
    while(++times<n){
        pq.push(1);
        changed= false;
        while (!pq.empty()){
            ll locate=pq.top();
            pq.pop();
            for(auto x:link[locate]){
                if(far[x.first]!=INF)
                    pq.push(x.first);
                if(far[x.first]>far[locate]+x.second){
                    far[x.first]=far[locate]+x.second;
                    changed= true;
                }
            }
        }
        if(!changed)
            break;
    }
    if(times==n && !changed)
        cout<<"YES\n";
    else if(times==n && changed)
        cout<<"NO\n";
    else
        cout<<"YES\n";
}