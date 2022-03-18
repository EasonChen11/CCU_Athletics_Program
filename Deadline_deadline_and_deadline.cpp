#include <iostream>
#include <algorithm>
using namespace std;
 struct HW{
    long long int work_day,deadline;
};
bool compare(struct HW a,struct HW b){
    return b.deadline > a.deadline;
}
int main(){
    int n;
    cin>>n;
    while (n-- ){
        int number_of_work;
        long long int  timing=0;
        cin>>number_of_work;
        struct HW student[105];
        for (int i = 0; i < number_of_work; ++i) {
            cin>>student[i].work_day;
        }
        for (int i = 0; i < number_of_work; ++i) {
            cin>>student[i].deadline;
        }
        sort(student,student+number_of_work,compare);
//        for (int i = 0; i < number_of_work; ++i) {
//            cout<<student[i].work_day<<student[i].deadline<<endl;
//        }
        long long int check;
        for (check = 0; check < number_of_work; ++check) {
            timing+=student[check].work_day;
            if(timing>student[check].deadline){
                break;
            }
        }
        if(check<number_of_work)
            cout<<"No";
        else
            cout<<"Yes";
        if(n!=0)
            cout<<"\n";
    }
}
