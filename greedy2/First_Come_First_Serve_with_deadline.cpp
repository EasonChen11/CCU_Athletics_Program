//想法:
//試一台機器到N台機器(最多N台)
//用二分搜一半可以往前直到不行往後
//直到找到最小機台數
//如果N台都不行輸出-1
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int jobs, deadline;
bool check(int machines, vector<int> &time)
{
    priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
    while (pq.size() != machines)
        pq.push(0);
    for (int i = 0; i < jobs; ++i)
    {
        int x = time[i];
        long long int temp = pq.top();
        pq.pop();
        temp += x;
        pq.push(temp);
    }
    while (!pq.empty())
    {
        if (pq.size() == 1)
        {
            if (pq.top() > deadline)
                return false;
        }
        pq.pop();
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> jobs >> deadline;
        vector<int> time(jobs);
        int max_time = 0;
        for (int &x : time)
        {
            cin >> x;
            max_time = max(x, max_time);
        }
        if (max_time > deadline)    //失敗條件:如果有一個job時間>deadline，再多機器都不可能完成
        {
            cout << "-1\n";
            continue;
        }
        int left = 1, right = jobs;
        int ans = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (check(mid, time))
            {
                ans = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        ans == -1 ? cout << "-1\n" : cout << ans << endl;
    }
}