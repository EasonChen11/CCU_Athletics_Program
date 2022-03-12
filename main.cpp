#include <iostream>
#include <map>

void prime_number_separate(long long int k, std::pair< int, int > map1);

using namespace std;
int main() {
    int n;
    cin>>n;
    while (n--){
        long long int k;
        map<int,int> prime_number_times;
        cin>>k;
        prime_number_sperate(k,prime_number_times);
        for (auto x:prime_number_times)
            cout<<x.first<<" "<<x.second;
        prime_number_times.clear();
        cout<<endl;
    }
    return 0;
}

void prime_number_separate(long long int k, map < int, int > map1) {

}
