#include<bits/stdc++.h>
#define MAXN 30005
using namespace std;
int n,m,w,cost[MAXN],value[MAXN],dp[MAXN];
int main(){
    cin>>n>>m;
    for(register int i=1;i<=m;++i){
        cin>>cost[i]>>w;
        value[i]=cost[i]*w;
    }
    for(register int i=1;i<=n;++i)
        for(register int j=n;j>=cost[i];--j)
            dp[j]=max(dp[j],dp[j-cost[i]]+value[i]);
    cout<<dp[n]<<endl;
}