#include <iostream>
#include <cmath>
#include <vector>
#include <set>
using namespace std;
int main() {
    long long int p, i, n= pow(10,3);//根號(max=10^12)
    vector<long long int>prime_number_list;
    set<long long int>Composite_number;
    for (long long int j = 2; j <= n; ++j) {
        if(Composite_number.count(j))
            continue;
        else
            prime_number_list.push_back(j);
        for (long long int k = j*j; k <= n; k+=j) {
            Composite_number.insert(k);
        }
    }
//for(auto x:prime_number_list)
//    cout<<x<<endl;
    while (cin>>p ){
        long long int k= pow(p,0.5);
        if(p==1){
            cout<<"oh no\n";
            continue;
        }
        for (i = 0; prime_number_list[i] <= k; ++i) {
            if(p%prime_number_list[i]==0){
                cout<<"oh no\n";
                break;
            }
        }
        if(prime_number_list[i]>k)
            cout<<"isprime\n";
    }
    return 0;
}