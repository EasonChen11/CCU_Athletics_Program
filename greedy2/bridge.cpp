#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    int people, i;
    cin >> people;
    vector<int> time(people);
    for (int &x : time)
        cin >> x;
    sort(begin(time), end(time));

    long long int sum = 0;

    for (i = people - 1; i >= 3; i -= 2)
    {                                                                      //三個人以上
        long long int reserve = time[1] + time[0] + time[i] + time[1];     // reserve
        long long int obvious = time[i] + time[0] + time[i - 1] + time[0]; // obvious
        sum += min(reserve, obvious);
    }
    if (i == 2)
        sum += (time[1] + time[0] + time[2]); //三個人
    else if (i == 1)
        sum += time[1]; //兩個人
    else if (i == 0)
        sum += time[0]; //一個人

    cout << sum << endl;
    return 0;
}