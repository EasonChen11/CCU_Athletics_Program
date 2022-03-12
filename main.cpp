#include <iostream>

bool household_quality(long long int x, long long int y);

using namespace std;
int main() {
    long long int x,y;
    while (cin>>x>>y){
        if(household_quality(max(x,y), min(x,y)))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}

bool household_quality(long long int x, long long int y) {
    if(x==1 || y==1)
        return true;
    else if(x==0 || y==0)
        return false;
    return household_quality(y,x%y);
}
