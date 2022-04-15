//
// Created by ysche on 2022/4/15.
//
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f3f3f3f3f
typedef long long ll;
int main(){
    ll n,m,q;
    cin>>n>>m>>q;
    vector<vector<ll>> city(n+1,(vector<ll>(n+1,INF)));
    for (ll i = 0; i < m; ++i) {
        pair<ll,ll> road;
        ll weight;
        cin>>road.first>>road.second>>weight;
        if(weight>city[road.first][road.second])
            continue;
        else {
            city[road.first][road.second] = weight;
            city[road.second][road.first] = weight;
        }
    }
    for (ll k = 1; k <= n; ++k) {
        for (ll i = 1; i <= n; ++i) {
            for (ll j = 1; j <= n; ++j) {
                city[j][j]=0;
                city[i][j]=min(city[i][j],city[i][k]+city[k][j]);
            }
        }
    }
    for (ll i = 0; i < q; ++i) {
        pair<ll,ll> save;
        cin>>save.first>>save.second;
        if(city[save.first][save.second]==INF)
            cout<<-1<<endl;
        else
            cout<<city[save.first][save.second]<<endl;
    }
}