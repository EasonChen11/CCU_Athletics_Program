#include <iostream>
using namespace std;
int ExGCD(int a,int b,int &x,int &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int r= ExGCD(b,a%b,x,y);
    int x1 =x;
    x=y;
    y=x1-(a/b*y);
    return r;
}
int main() {
    int a,b,x,y;
    cin>>a>>b;
    ExGCD(a,b,x,y);
    cerr<<x<<
    return 0;
}