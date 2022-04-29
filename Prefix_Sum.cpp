#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main() {
    ll n,p;
    cin>>n>>p;
    vector<ll> Sum(n+1,0);
    for (ll i = 1; i <= n; ++i) {
        ll save;
        cin>>save;
        Sum[i]=save+Sum[i-1];
    }
    for (ll i = 0; i < p; ++i) {
        pair<ll,ll> save;
        cin>>save.first>>save.second;
        cout<<Sum[save.second]-Sum[save.first-1]<<endl;
    }
    return 0;
}