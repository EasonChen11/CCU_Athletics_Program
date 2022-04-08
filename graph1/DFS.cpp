//
// Created by ysche on 2022/4/8.
//根是最開頭
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

typedef struct {
    int weight;
    vector<int> r;
}D;

int main(){
    int point,edge,root;
    cin>>point>>edge>>root;
    vector<D> roots(point);//graph
    vector<bool> visit(point, false);
    for (int i = 0; i < point; ++i) {
        cin>>roots[i].weight;
    }
    for (int i = 0; i < edge; ++i) {
        pair<int,int> link;
        cin>>link.first>>link.second;
        roots[link.first-1].r.push_back(link.second-1);
        roots[link.second-1].r.push_back(link.first-1);

    }
    for(int i=0;i<point;i++){
        sort(roots[i].r.begin(),roots[i].r.end(),[&](int a,int b){
            if(roots[a].weight!=roots[b].weight){
                return roots[a].weight>roots[b].weight;
            }
            else {
                return a>b;
            }
        });
    }
    stack<int> st;
    st.push(root-1);
    while ( !st.empty()){
        int node=st.top();
        st.pop();
        if(visit[node])
            continue;
        cout<<node+1<<" ";
        visit[node]= true;
        for(auto i:roots[node].r){
            if(visit[i])
                continue;
            st.push(i);
        }
    }
    return 0;
}