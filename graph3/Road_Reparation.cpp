#include <bits/stdc++.h>

using namespace std;

int main(){
    int total_city,total_edge;
    cin>>total_city>>total_edge;
    vector<vector<pair<int,int>>> city_to_city(total_city+1);
    for(int i=1;i<=total_edge;i++){
        int first;
        pair<int,int> input;
        cin>>first>>input.second>>input.first;
        city_to_city[first].push_back(input);
        city_to_city[input.second].push_back({input.first,first});
    }
    vector<bool> visit(total_city+1, false);
    long long int ans_weight=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});
    while (!pq.empty()){
        int now_point=pq.top().second,weight=pq.top().first;
        pq.pop();
        if(visit[now_point])
            continue;
        visit[now_point]=true;
        ans_weight+=weight;
        for(auto x:city_to_city[now_point]){
            if(visit[x.second])
                continue;
            pq.push(x);
        }
    }
    for(int i=1;i<=total_city;i++){
        if(!visit[i]){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }
    cout<<ans_weight<<endl;
    return 0;
}
