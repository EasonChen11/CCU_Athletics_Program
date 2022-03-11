#include <iostream>
using namespace std;
typedef struct CycleAndTiming{
    int t,d;
};
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
    int x,y,n,X=0,M=1;
    cin>>n;
    CycleAndTiming list[5]={0,0};
    for (int i = 0; i < n; ++i) {
        cin>>list[i].t>>list[i].d;
        M*=list[i].t;
    }
    for (int i = 0; i < n; ++i) {
        ExGCD(list[i].d,list[i].t,x,y);
        if (x<0)
            x+=list[i].t;
        X+=list[i].d*x*(M/list[i].t);
        cerr<<M/list[i].t<<"*"<<x<<" "<<list[i].t<<endl;
    }
    //cout<<X;
    return 0;
}