#include<bits/stdc++.h>
using namespace std;
int n,m,ans,dis[1005][1005];
int main(){
    cin>>n>>m;
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=n;++j)
            if(i!=j)dis[i][j]=1000000000;
    for(register int i=1;i<=m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        dis[u][v]=min(dis[u][v],w);
    }
    for(register int k=1;k<=n;++k)
        for(register int i=1;i<=n;++i)
            for(register int j=1;j<=n;++j)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(register int i=2;i<=n;++i)ans+=(dis[1][i]+dis[i][1]);
    cout<<ans<<endl;
}