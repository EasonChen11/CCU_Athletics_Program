#include <iostream>
#include<algorithm>
#include <vector>
#include <queue>
using namespace std;
int main() {
    int nodes,edge;
    cin>>nodes>>edge;
    vector<vector<int>> root(nodes);
    vector<bool> visit(nodes, false);
    vector<int> points(nodes);
    for(int &x:points)
        cin>>x;
    for (int i = 0; i < edge; ++i) {
        pair<int,int> link;
        cin>>link.first>>link.second;
        root[link.first-1].push_back(link.second-1);
        root[link.second-1].push_back(link.first-1);
    }
    vector<long long int> ans(nodes,0);
    queue<int> st;
    for (int i = 0; i < nodes; ++i) {
        if(visit[i])
            continue;
        st.push(i);
        while (!st.empty() ){
            int node=st.front();
            st.pop();
            if(visit[node])
                continue;
            visit[node]=true;
            ans[i]+=points[node];
            for(auto x:root[node]){
                st.push(x);
            }
        }
    }
    sort(ans.begin(),ans.end());
    for(auto x:ans){
        if(x)
            cout<<x<<" ";
    }
    return 0;
}