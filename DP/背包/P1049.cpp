#include<bits/stdc++.h>
#define MAXN 20005
using namespace std;
int t,m,dp[MAXN],tim[MAXN];
int main(){
    cin>>t>>m;
    for(register int i=1;i<=m;++i)cin>>tim[i];
    for(register int i=1;i<=m;++i)
        for(register int j=t;j>=tim[i];--j)
            dp[j]=max(dp[j],dp[j-tim[i]]+tim[i]);
    cout<<t-dp[t]<<endl;
}