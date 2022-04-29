#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pll;
int main(){
    ll n,m;//n個package,total_weight<=m
    cin>>n>>m;
    vector<ll> DP_graph(m+1,0);
    for (ll i = 1; i <= n; ++i) {
        pll pack;//{weight,value}
        cin>>pack.first>>pack.second;
        for (ll j = m; j >= 0; --j) {
            if(j<pack.first)
                break;
            DP_graph[j]=max(DP_graph[j],DP_graph[j-pack.first]+pack.second);
        }
    }
    cout<<DP_graph[m]<<endl;

}