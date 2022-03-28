//想法:
//試一台機器到N台機器(最多N台)
//如果N台都不行輸出-1
//不可以是0可以是1
//{0,0,0,1,1,1,1....}
//用二分搜找第一個1
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
    int T;
    cin>>T;
    while (T-- ){
        long long int Case_number,deadline,machine_number=0,Case_time[100000];

        cin>>Case_number>>deadline;
        for (int i = 0; i < Case_number; ++i) {
            cin>>Case_time[i];
        }
        while (machine_number++<Case_number){
            priority_queue<long long int ,vector<long long int>,greater<long long int >> pq;
            while (pq.size() <machine_number )
                pq.push(0);
            for (int i = 0; i < Case_number; ++i) {
                long long int save=pq.top();
                save+=Case_time[i];
                pq.pop();
                pq.push(save);
            }
            while(pq.empty()==0){
                if(pq.size()==1)
                    pq.top()<deadline
                pq.pop();
            }
        }


    }
}
