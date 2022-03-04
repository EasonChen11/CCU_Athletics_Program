#include <iostream>
#include <cmath>
using namespace std;
int main() {
    long long int p,i;
    while (cin>>p ){
        if(p==1){
            cout<<"oh no\n";
            continue;
        }
        long long int k= pow(p,0.5);
        for(i=2;i<=k;i++){
            if(p%i==0){
                cout<<"oh no\n";
                break;
            }
        }
            if(i>k)
                cout<<"isprime\n";
    }
    return 0;
}