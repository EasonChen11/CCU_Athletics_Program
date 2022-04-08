//
// Created by ysche on 2022/4/8.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int root,edge,question;
    cin>>root>>edge>>question;
    vector<vector<int>> point(root);
    for (int i = 0; i < edge; ++i) {
        pair<int,int> link;
        cin>>link.first>>link.second;
        if(std::find(point[link.first-1].begin(), point[link.first-1].end(),link.second-1 )==point[link.first-1].end())
            point[link.first-1].push_back(link.second-1);
    }
    for (int i = 0; i < question; ++i) {
        int q;
        cin>>q;
        q--;
        if(point[q].empty()){
            cout<<-1<<endl;
        } else{
            sort(point[q].begin(),point[q].end());
            for(int x:point[q]){
                cout<<x+1<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}