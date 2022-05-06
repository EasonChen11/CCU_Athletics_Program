#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long int ll;

int main(){
    ll len,max_len_of_ans=1;
    cin>>len;
    vector<ll> ans_list(len,INF);
    vector<ll> number_list(len);//input
    for(ll &x:number_list)
        cin>>x;
    ans_list[0]=number_list[0];
    for(int i=1;i<len;i++){
        if(number_list[i]>ans_list[max_len_of_ans-1]){
            ans_list[++max_len_of_ans-1]=number_list[i];
        }else{
            ll left=0,right=max_len_of_ans,middle;
            while ( left<right ){
                middle=(left+right)/2;
                if(ans_list[middle]<number_list[i]){
                    left=middle+1;
                }else{
                    right=middle;
                }
            }
            ans_list[left]=number_list[i];
        }
    }
    cout<<max_len_of_ans;
    return 0;
}