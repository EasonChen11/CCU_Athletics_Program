#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    while (n-- ){
        double x[2],y[2],try1,try2;
        cin>>x[0]>>x[1]>>y[0]>>y[1];
        //cout<<x[0]
        try1=pow(pow(x[0],2)+ pow(y[0],2),0.5) + pow(pow(x[1],2)+ pow(y[1],2),0.5);
        try2=pow(pow(x[0],2)+ pow(y[1],2),0.5) + pow(pow(x[1],2)+ pow(y[0],2),0.5);
        cout<<try1<<" "<<try2<<endl;
        cout<<(int) max(try1,try2)<<endl;
    }
}
