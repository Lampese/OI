#include<bits/stdc++.h>
#define MAXN 10005
using namespace std;
long long t,m,cost[MAXN],value[MAXN],f[10000005];
int main(){
    cin>>t>>m;
    for(register long long i=1;i<=m;++i)cin>>cost[i]>>value[i];
    for(register long long i=1;i<=m;++i)
        for(register long long j=cost[i];j<=t;++j)
            f[j]=max(f[j],f[j-cost[i]]+value[i]);
    cout<<f[t]<<endl;
}