#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
int t,n,m,cost[MAXN][MAXN],f[10000000];
int main(){
    cin>>t>>n>>m;
    for(register int i=1;i<=t;++i)
        for(register int j=1;j<=n;++j)
            cin>>cost[i][j];
    for(register int i=1;i<t;++i){
        memset(f,0,sizeof(f));
        for(register int j=1;j<=n;++j)
            for(register int k=cost[i][j];k<=m;++k)
                f[k]=max(f[k],f[k-cost[i][j]]+cost[i+1][j]-cost[i][j]);
        m+=f[m];
    }
    cout<<m<<endl;
}