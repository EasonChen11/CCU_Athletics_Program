#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pll;
int main(){
    ll n,m;//n個package,total_weight<=m
    cin>>n>>m;
    vector<pair<ll ,vector<ll>>> DP_graph(m+1);//{ value , {which item} }
    for (int i = 1; i <= m; ++i) {
        DP_graph[i].first=0;
    }
    for (ll i = 0; i < n; ++i) {
        pll pack;//{weight,value}
        cin>>pack.first>>pack.second;
        for (ll j = m; j >= 0; --j) {
            if(j<pack.first)
                break;
            if(DP_graph[j].first<DP_graph[j-pack.first].first+pack.second){
                DP_graph[j].first=DP_graph[j-pack.first].first+pack.second;
                DP_graph[j].second.push_back(i);
            }
            cout<<i+1<<":"<<endl;
//            for (int k = 1; k <=m ; ++k) {
//                cout<<DP_graph[k].first<<endl;
//                for(ll x:DP_graph[k].second)
//                    cout<<x<<" ";
//                cout<<endl;
//            }
        }
    }
    cout<<DP_graph[m].first<<endl<<DP_graph[m].second.size()<<endl;
    for(ll x:DP_graph[m].second)
        cout<<x<<" ";
    cout<<endl;
}