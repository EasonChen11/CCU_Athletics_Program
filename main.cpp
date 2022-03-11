#include <iostream>

long long int fast_number(long long int x, long long int y, long long int n);

using namespace std;
int main() {
    long long int a,n;
    cin>>a>>n;
    cout<< fast_number(a, n - 2, n);
    return 0;
}

long long int fast_number(long long int x, long long int y, long long int p) {
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
