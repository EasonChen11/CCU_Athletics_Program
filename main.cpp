#include <iostream>
#include <cmath>
#include <vector>
#include <set>
using namespace std;
int main() {
    long long int p,n= pow(10,12);
    vector<long long int>prime_number_list;
    set<long long int>Composite_number;
    for (long long int j = 2; j <= n; ++j) {
        if(Composite_number.count(j))
            continue;
        else
            prime_number_list.push_back(j);
        for (long long int k = j*j; k < n; k+=j) {
            Composite_number.insert(k);
//            for(auto x:Composite_number)
//                cout<<x<<endl;
        }
    }
//    for(auto x:prime_number_list)
//        cout<<x<<endl;

    while (cin>>p ){
        if(p==1){
            cout<<"oh no\n";
            continue;
        }
        if(Composite_number.count(p))
            cout<<"isprime\n";
        else
            cout<<"oh no\n";
    }
    return 0;
}