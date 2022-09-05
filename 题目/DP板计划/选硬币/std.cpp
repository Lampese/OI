#include<bits/stdc++.h>
using namespace std;
const int INF=2147483647;
int m,cost,f[10000005];
int main(){
    cin>>m;
    for(register int i=1;i<=m;++i){
        cost=INF;
        if(i>=1)cost=min(cost,f[i-1]+1);
        if(i>=5)cost=min(cost,f[i-5]+1);
        if(i>=11)cost=min(cost,f[i-11]+1);
        f[i]=cost;
    }
    cout<<f[m]<<endl;
}