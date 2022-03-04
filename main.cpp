#include <iostream>

long long int fp(long long int x, long long int y, long long int p);

using namespace std;
int main() {
    long long x,y,p;
    cin>>x>>y>>p;
    cout << fp(x,y,p);
    return 0;
}

long long int fp(long long int x, long long int y, long long int p) {
    long long int res=1;
    while (y!=0 ){
        if(y%2==1){
            res*=x;
            res%=p;
        }
        x*=x;
        x%=p;
        y/=2;
    }
    return res;
}
