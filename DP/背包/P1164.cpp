#include<bits/stdc++.h>
#define MAXN 20005
using namespace std;
int t,m,dp[MAXN],cost[MAXN];
int main(){
    cin>>m>>t;
    for(register int i=1;i<=m;++i)cin>>cost[i];
    dp[0]=1;
    for(register int i=1;i<=m;++i)
        for(register int j=t;j>=cost[i];--j)
            dp[j]+=dp[j-cost[i]];
    cout<<dp[t]<<endl;
}