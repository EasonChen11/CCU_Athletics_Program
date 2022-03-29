#include <iostream>
#include <algorithm>
int coin_item_number=0,money;
int coin_number[20]={0};
void change_coin(int max_number);

using namespace std;
int main() {
    int n;
    cin>>n>>money;
    for (int i = 0; i < n; ++i) {
        cin>>coin_number[i];
    }
    sort(coin_number,coin_number+n-1);
    change_coin(n - 1);
    if(coin_number==0 || money!=0)
        cout<<-1;
    else
        cout<< coin_item_number;
    return 0;
}

void change_coin(int max_number) {
    if(money>=coin_number[max_number]){
        money-=coin_number[max_number];
        coin_item_number++;
        change_coin(max_number);
    }else if(money<coin_number[0])
        return ;
    else{
        change_coin(max_number - 1);
    }
}
