#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n;
    long long int D,x;
    cin>>n>>D;
    vector<long long int> list;
    for (int i = 0; i < n; ++i) {
        cin>>x;
        list.push_back(x);
    }
    sort(list.begin(),list.end(),less<long long int>());
    long long int i,k=0;
    for (i = 0; i < n; ++i) {
        k+=list[i];
        if(k>D){
            k-=list[i];
            break;
        }
        list[i+1]+=list[i];
    }

    cout<<i<<" "<<k;
}