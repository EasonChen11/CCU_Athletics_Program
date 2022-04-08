#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    int row, col;
    cin >> row >> col;
    vector<vector<char>> graph(row, vector<char>(col));
    queue<pair<int, int>> q;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 'A')
                q.push({i, j});
        }
    int dir[5] = {0, 1, 0, -1, 0};//(0,1),(1,0),(0,-1),(-1,0)
    int ans = 0;
    while (!q.empty())
    {
        unsigned long long int size = q.size();
        while (size--)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();//在q點
            if(graph[x][y]=='#')
                continue;
            if (graph[x][y] == 'B')
            {
                cout << "YES\n";
                cout << ans << endl;
                return 0;
            }
            graph[x][y] = '#';
            for (int k = 0; k < 4; k++)
            {
                int i = x + dir[k];
                int j = y + dir[k + 1];
                if (i >= 0 && i < row && j >= 0 && j < col && graph[i][j] != '#')
                    q.push({i, j});
            }
        }
        ans++;
    }
    cout << "NO\n";
    return 0;
}