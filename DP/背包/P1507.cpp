#include<bits/stdc++.h>
using namespace std;
int n,VM,MM,v[55],m[55],w[55],dp[55][405][405];
int main(){
    cin>>VM>>MM>>n;
    for(register int i=1;i<=n;++i)cin>>v[i]>>m[i]>>w[i];
    for(register int i=1;i<=n;++i){
        for(register int j=0;j<=VM;++j)
            for(register int k=0;k<=MM;++k){
                if(j<v[i]||k<m[i])dp[i][j][k]=dp[i-1][j][k];
                else dp[i][j][k]=max(dp[i-1][j][k],dp[i-1][j-v[i]][k-m[i]]+w[i]);
            }
    }
    cout<<dp[n][VM][MM]<<endl;
}