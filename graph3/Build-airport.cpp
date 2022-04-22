#include <bits/stdc++.h>
using namespace std;
class Union_find{
public:
    int parent[1000+5],Size[1000+5];
    void init(){
        for (int i = 1; i <= 1000+5; ++i) {
            parent[i]=i;
            Size[i]=1;
        }
    }
    int Finds(int x){
        if(parent[x]==x)
            return x;
        return parent[x]= Finds(parent[x]);//尋找father
    }
    void Union(int a,int b){
        int x= Finds(a);
        int y= Finds(b);
        if(x==y)
            return;
        if(Size[x]>Size[y])
            swap(x,y);
        parent[x]=parent[y];
        Size[y]+=Size[x];//往大的樹加
    }
};
int main() {
    int node,edge;
    cin>>node>>edge;
    Union_find solution;
    solution.init();
    for (int i = 0; i < edge; ++i) {
        int a,b;
        cin>>a>>b;
        if(solution.Finds(a)==solution.Finds(b))continue;
        solution.Union(a,b);
    }
    int ans=0;
    for (int z=1;z<=node;z++) {
        if(solution.parent[z]==z) ans++;
    }
    if(ans<=1)
        cout<<0<<endl;
    else
        cout<<ans<<endl;
    return 0;
}