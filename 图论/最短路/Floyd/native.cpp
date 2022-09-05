#include<bits/stdc++.h>
using namespace std;
int f[105][105];
int main(){
    int n,m,u,v,w;
    cin>>n>>m;
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=n;++j){
            if(i==j)f[i][j]=0;
            else f[i][j]=100000000;
        }
    for(register int i=1;i<=m;++i){
        cin>>u>>v>>w;
        f[u][v]=min(f[u][v],w);
        f[v][u]=f[u][v];
    }
    for(register int k=1;k<=n;++k)
        for(register int i=1;i<=n;++i)
            for(register int j=1;j<=n;++j)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    for(register int i=1;i<=n;++i){
        for(register int j=1;j<=n;++j)
            cout<<f[i][j]<<" ";
        cout<<endl;
    }
}