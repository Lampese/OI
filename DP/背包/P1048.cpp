#include<bits/stdc++.h>
#define MAXN 1005
using namespace std;
int t,m,dp[MAXN],tim[MAXN],w[MAXN];
int main(){
    cin>>t>>m;
    for(register int i=1;i<=m;++i)cin>>tim[i]>>w[i];
    for(register int i=1;i<=m;++i)
        for(register int j=t;j>=tim[i];--j)
            dp[j]=max(dp[j],dp[j-tim[i]]+w[i]);
    cout<<dp[t]<<endl;
}