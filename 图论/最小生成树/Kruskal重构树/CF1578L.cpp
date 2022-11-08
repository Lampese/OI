#include<bits/stdc++.h>
#define MAXN 300005
using namespace std;
long long n,m,cnt,head[MAXN],dp[MAXN],sum[MAXN],f[MAXN];
struct edge{
    long long u,v,w;
}e[MAXN];
inline bool cmp(edge &a,edge &b){
    return a.w>b.w;
}
inline int find(int x){
    return x==f[x]?x:f[x]=find(f[x]);
}
int main(){
    cin>>n>>m;
    cnt=n;
    memset(dp,0x3f,sizeof dp);
    for(register int i=1;i<=n;++i)cin>>sum[i];
    for(register int i=1;i<=m;++i)cin>>e[i].u>>e[i].v>>e[i].w;
    for(register int i=1;i<=n*2;++i)f[i]=i;
    sort(e+1,e+m+1,cmp);
    for(register int i=1;i<=m;++i){
        int u(e[i].u),v(e[i].v);
        u=find(u),v=find(v);
        if(u!=v){
            f[u]=f[v]=++cnt;
            dp[cnt]=max(min(e[i].w,dp[u])-sum[v],min(e[i].w,dp[v])-sum[u]);
            sum[cnt]=sum[u]+sum[v];
        }
        if((cnt-n)==n-1)break;
    }
    if(dp[cnt]<=0)cout<<-1<<endl;
    else cout<<dp[cnt]<<endl;
}