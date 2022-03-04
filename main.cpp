#include <iostream>

long long int fp(int x, int y, int p);

using namespace std;
int main() {
    int x,y,p;
    cin>>x>>y>>p;
    cout << fp(x,y,p);
    return 0;
}

long long int fp(int x, int y, int p) {
    int res=1;
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
