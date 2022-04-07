#include <iostream>
#include<algorithm>
#include <vector>
#include <functional>
using namespace std;
int main() {
    int node,edge;
    cin>>node>>edge;
    vector<int> root(node);
    for (int i = 0; i < node; ++i) {
        root[i]=i;
    }
    vector<int> points(node);
    for(int &x:points)
        cin>>x;
    function<int(int)> find = [&](int x){
        return x==root[x] ? x : root[x]=find(root[x]);
    };
    for (int i = 0; i < edge; ++i) {
        pair<int,int> p,p_root;
        cin>>p.first>>p.second;
        p_root.first=find(--p.first);
        p_root.second=find(--p.second);
        if(p_root.first!=p_root.second){
            root[p_root.second]=p_root.first;
        }
    }
    vector<int> ans(node,0);
    for (int i = 0; i <node ; ++i) {
        ans[find(i)]+=points[i];
    }
    sort(begin(ans), end(ans));
    for (int x:ans) {
        if(x==0)
            continue;
        cout<<x<<" ";
    }
    return 0;
}