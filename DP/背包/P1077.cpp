#include<bits/stdc++.h>
using namespace std;
int n,m,v[105],dp[105];
int main(){
    cin>>n>>m;
    for(register int i=1;i<=n;++i)cin>>v[i];
    dp[0]=1;
    for(register int i=1;i<=n;++i)
        for(register int j=m;j>=0;--j)
            for(register int k=1;k<=min(v[i],j);++k)
                dp[j]+=dp[j-k],dp[j]%=1000007;
    cout<<dp[m];
}