#include <iostream>
#include <algorithm>
using namespace std;
int win_number(int * enemies, int enemies_number, int * soldiers, int soldiers_number, int n, int win);
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
        sort(enemies,enemies+n,less<int>());//升序：sort(begin, end, less<Type>());
        sort(soldiers,soldiers+n,less<int>());//降序：sort(begin, end, greater<Type>());
        cout << win_number(enemies, 0, soldiers, 0, n, 0) << endl;
    }
}
int win_number(int * enemies, int enemies_number, int * soldiers, int soldiers_number, int n, int win) {
    if(enemies_number>=n || soldiers_number>=n)
        return win;
    if(enemies[enemies_number]<soldiers[soldiers_number]){
       return win_number(enemies,enemies_number+1,soldiers,soldiers_number+1,n,win+1);
    } else if(enemies[enemies_number]>soldiers[soldiers_number]){
        return win_number(enemies,enemies_number,soldiers,soldiers_number+1,n,win);
    } else{
        return win_number(enemies,enemies_number+1,soldiers,soldiers_number+1,n,win);
    }
}
