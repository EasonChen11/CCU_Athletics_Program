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
    for(ll now_number=1;now_number<=m;now_number++){
        for(int i=0;i<n;i++){
            if(now_number-denomination[i]<0){
                break;
            }
            visit[now_number]=min(visit[now_number],visit[now_number-denomination[i]]+1);
        }
    }
    if(visit[m]==INF)
        cout<<-1<<endl;
    else
        cout<<visit[m]<<endl;
}