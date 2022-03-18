#include <iostream>
#include <algorithm>

using namespace std;
int win_number(int*,int*,int);
int main(){
    int n;
    while (cin>>n,n ){
        int soldiers[10005]={0},enemies[10005]={0};
        for (int i = 0; i < n; ++i) {
            cin>>enemies[i];
        }
        for (int i = 0; i < n; ++i) {
            cin>>soldiers[i];
        }
        sort(enemies,enemies+n,greater<int>());//升序：sort(begin, end, less<Type>());
        sort(soldiers,soldiers+n,greater<int>());//降序：sort(begin, end, greater<Type>());
        int k;
        cout<<win_number(enemies,soldiers,n)<<endl;
    }
}
int win_number(int* enemies,int* soldiers,int n){

}
