#include <iostream>
#include <map>
#include <cmath>
using namespace std;
map < long long int, int > prime_number_separate(long long int k);


bool prime_number(long long int i);

int main() {
    int n;
    cin>>n;
    while (n--){
        long long int k;
        cin>>k;
        map<long long int,int> prime_number_times = prime_number_separate(k);
        for (auto x:prime_number_times)
            cout<<x.first<<" "<<x.second<<" ";
        prime_number_times.clear();
        cout<<endl;
    }
    return 0;
}

map < long long int, int > prime_number_separate(long long int k) {
    const long long int x=k;
    map<long long int,int> prime_number_times;
    prime_number_times.clear();
    for (long long int i = 2; i <= x; ++i) {
        if(k==1)
            break;
            while (k%i==0){
                k/=i;
                prime_number_times[i]++;
            }
    }
    return prime_number_times;
}

/*bool prime_number(long long int i) {
    double d= sqrt(i);
    for (long long int j = 2; j <= d; ++j) {
        if(i%j==0)
            return false;
    }
    return true;
}*/
