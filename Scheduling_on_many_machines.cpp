#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdlib>
using namespace std;
//想法:
// 把一個任務放入機器(先讓機器任務時數=0)，
// 在放入下一個任務進入目前總和時間最小的機器
// 排序機器總和時間
//重複以上，最後輸出最常機器的時間
int compare(void const* a,void const *b){
    return *(long long int *)b<*(long long int *)a;
}

int main(){
    int T;
    cin>>T;
    while (T-- ){
        int Case_number,machines_number;
        cin>>Case_number>>machines_number;
        long long int Case_time;
        long long int *machines_time = (long long int*)calloc(machines_number,sizeof (long long int));
        for (int i = 0; i < Case_number; ++i) {
            cin>>Case_time;
            machines_time[0]+=Case_time;
            //qsort(machines_time,machines_number, sizeof(long long int ),compare);
            sort(machines_time,machines_time+machines_number,less<long long int>());
        }
        cout<<machines_time[machines_number-1]<<endl;
        free(machines_time);
    }
}
