#include<bits/stdc++.h>
#define MAXN 505
using namespace std;
int cost[MAXN],fr[MAXN],be[MAXN],dp[MAXN][MAXN],upre[MAXN][MAXN],pre[MAXN][MAXN];
int main(){
    int n,q;
    cin>>n>>q;
    for(register int i=1;i<=n;++i)cin>>cost[i]>>fr[i]>>be[i];
    for(register int i=0;i<=500;++i)
        for(register int j=0;j<=501;++j){
            dp[i][j]=upre[i][j]=pre[i][j]=INT_MIN;
        }
    dp[0][0]=0;
    for(register int i=1;i<=n;++i){
        for(register int j=500;j>=cost[i];--j){
            for(register int k=501;k>=501-fr[i];--k){
                dp[j][501]=max(dp[j][501],dp[j-cost[i]][k]+be[i]);
            }
            for(register int k=500;k>=fr[i];--k){
                dp[j][k]=max(dp[j][k],dp[j-cost[i]][k-fr[i]]+be[i]);
            }
        }
    }
    for(register int i=0;i<=500;++i)
        for(register int j=501;j>=0;--j)
            upre[i][j]=max(dp[i][j],upre[i][j+1]);
    for(register int i=0;i<=500;++i)
        for(register int j=0;j<=501;++j)
            pre[i][j]=max(upre[i][j],pre[max(0,i-1)][j]);
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<pre[x][y]<<endl;
    }
}