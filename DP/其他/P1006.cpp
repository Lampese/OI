#include<bits/stdc++.h>
#define MAXN 55
using namespace std;
int m,n,Map[MAXN][MAXN],dp[MAXN][MAXN][MAXN][MAXN];
int main(){
    cin>>m>>n;
    for(register int i=1;i<=m;++i)
        for(register int j=1;j<=n;++j)
            cin>>Map[i][j];
    for(register int i=1;i<=m;++i)
        for(register int j=1;j<=n;++j)
            for(register int k=1;k<=m;++k)
                for(register int l=1;l<=n;++l){
                    dp[i][j][k][l]=max(max(dp[i-1][j][k-1][l],dp[i-1][j][k][l-1]),max(dp[i][j-1][k-1][l],dp[i][j-1][k][l-1]))+Map[i][j]+Map[k][l];
                    if(i==k&&j==l)dp[i][j][k][l]-=Map[i][j];
                }
    cout<<dp[m][n][m][n]<<endl;
}