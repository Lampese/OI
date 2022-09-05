#include<bits/stdc++.h>
#define MAXN 55
using namespace std;
int n,m,ecnt,ans=-1,head[MAXN];
bitset<MAXN>vis;
struct edge{
    int v,next,w;
}e[MAXN<<1];
inline void add(int u,int v,int w){
    e[++ecnt]={v,head[u],w};
    head[u]=ecnt;
}
void dfs(int u,int sum){
    vis[u]=1;
    for(register int i=head[u];i;i=e[i].next)
        if(vis[e[i].v])continue;
        else{
            ans=max(ans,sum+e[i].w);
            dfs(e[i].v,sum+e[i].w);
        }
    vis[u]=0;
}
int main(){
    int u,v,w;
    cin>>n>>m;
    for(register int i=1;i<=m;++i){
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    for(register int i=1;i<=n;++i){
        vis.reset();
        dfs(i,0);
    }
    cout<<ans<<endl;
}