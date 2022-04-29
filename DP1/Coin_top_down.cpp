#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long int ll;

int main(){
    ll n;
    ll m;//m=total money
    cin>>n>>m;
    vector<ll> denomination(n);//面額
    for (ll &x:denomination) {
        cin>>x;
    }
    sort(denomination.begin(),denomination.end());
    vector<ll> visit(m+1,INF);
    visit[0]=0;
    function<ll(ll)> DP=[&](ll less_number){
        if(visit[less_number]!=INF)
            return visit[less_number];
        for (int i = 0; i < n; ++i) {
            if(less_number<denomination[i])
                return ll(1);
            else
                visit[less_number]=min(DP(less_number-denomination[i]),visit[less_number])+1;
        }
    };
    DP(m);
    for(int x=1;x<=m;x++)
        cout<<x<<":"<<visit[x]<<endl;
//    if(visit[m]==INF)
//        cout<<-1<<endl;
//    else
//        cout<<visit[m]<<endl;
}