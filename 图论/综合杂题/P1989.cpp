#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
int head[MAXN],du[MAXN],from[MAXN],to[MAXN],vis[MAXN],ans,ecnt;
struct edge{
    int v,next;
}e[MAXN<<1];
inline void add(int u,int v){
    e[++ecnt]={v,head[u]};
    head[u]=ecnt;
}
int main(){
    int n,m,u,v;
    cin>>n>>m;
    for(register int i=1;i<=m;++i){
        cin>>from[i]>>to[i];
        ++du[from[i]],++du[to[i]];
    }
    for(register int i=1;i<=m;++i)
        if(du[from[i]]<du[to[i]])add(from[i],to[i]);
        else if(du[from[i]]==du[to[i]]&&from[i]<to[i])add(from[i],to[i]);
        else add(to[i],from[i]);
    for(register int i=1;i<=n;++i){
        for(register int j=head[i];j;j=e[j].next)vis[e[j].v]=i;
        for(register int j=head[i];j;j=e[j].next)
            for(register int k=head[e[j].v];k;k=e[k].next)
                if(vis[e[k].v]==i)
                    ++ans;
    }
    cout<<ans<<endl;
}