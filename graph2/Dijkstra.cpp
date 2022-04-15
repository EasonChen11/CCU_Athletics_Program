//
// Created by ysche on 2022/4/15.
//
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
typedef long long ll;
using namespace std;
int main(){
    ll nodes,line;
    cin>>nodes>>line;
    vector<vector<pair<ll,ll>>> link(nodes+1);
    for (ll i = 0; i < line; ++i) {
        pair<ll,ll> p;
        ll weight;
        cin>>p.first>>p.second>>weight;
        link[p.first].push_back({p.second,weight});
    }
    vector<bool> visit(nodes+1, false);
    vector<ll> far(nodes+1,INF);//{how far to 1,the in front poll}
    far[1]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,1});
    while (!pq.empty() ){
        ll locate=pq.top().second,how_far=pq.top().first;
        pq.pop();
        if(visit[locate])
            continue;
        visit[locate]=true;
        for(auto x:link[locate]){
            if(visit[x.first])
                continue;
            if(far[x.first]>(how_far+x.second)){
                far[x.first]=how_far+x.second;
            }
            pq.push({far[x.first],x.first});
        }
    }
    for(ll x=1;x<=nodes;x++){
        cout<<far[x]<<" ";
    }
}