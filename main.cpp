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
    a=23;
    b=9;
    ExGCD(a,b,x,y);
    cerr<<"ax+by = "<<a*x+b*y <<endl;
    return 0;
}