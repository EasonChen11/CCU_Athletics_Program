#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    cin.ignore();
    while (n-- ){
        string sx,sy;
        getline(cin,sx);
        getline(cin,sy);
        stringstream ssx(sx),ssy(sy);
        vector<int> x,y;
        int tempx ,tempy;
        while (ssx>>tempx,ssy>>tempy ){
            x.push_back(tempx);
            y.push_back(tempy);
        }
        sort(x.begin(),x.end(),greater<int>());
        sort(y.begin(),y.end(),less<int>());
        double sum1=0;
        long long int l1;
        for (int i=0;i<x.size();i++) {
            l1=pow(x[i],2)+ pow(y[i],2);
            sum1+= sqrtl(l1);
        }

        sort(x.begin(),x.end(),less<int>());
        sort(y.begin(),y.end(),greater<int>());
        double sum2=0;
        long long int l2;
        for (int i=0;i<x.size();i++) {
            l2=pow(x[i],2)+ pow(y[i],2);
            sum2+= sqrtl(l2);
        }
        cout<<(long long int) max(sum1,sum2)<<endl;
    }
}