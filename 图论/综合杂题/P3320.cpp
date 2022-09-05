#include<bits/stdc++.h>
#define MAXN 100005
using namespace std; 
bitset<MAXN>vis;
long long head[MAXN],_size[MAXN],father[MAXN],deep[MAXN],top[MAXN],dfn[MAXN],big[MAXN],dis[MAXN],sq[MAXN];;
long long ecnt,nowtime;
struct edge{
    long long v,next,w;
}e[MAXN<<1];
inline void add(long long u,long long v,long long w){
    e[++ecnt]={v,head[u],w},head[u]=ecnt;
    e[++ecnt]={u,head[v],w},head[v]=ecnt;
}
void dfs1(long long now,long long fa){
    _size[now]=1,father[now]=fa,deep[now]=deep[fa]+1;
    for(register long long i=head[now];i;i=e[i].next){
        long long v(e[i].v);
        if(v==fa)continue;
        dis[v]=dis[now]+e[i].w;
        dfs1(v,now);
        _size[now]+=_size[v];
        if(big[now]==0||_size[big[now]]<_size[v])big[now]=v;
    }
}
void dfs2(long long now,long long fa){
    top[now]=fa,dfn[now]=++nowtime,sq[nowtime]=now;
    if(big[now])dfs2(big[now],fa);
    for(register long long i=head[now];i;i=e[i].next){
        long long v(e[i].v);
        if(v==father[now]||v==big[now])continue;
        dfs2(v,v);
    }
}
inline long long lca(long long a,long long b){
    while(top[a]!=top[b]){
        if(deep[top[a]]<deep[top[b]])swap(a,b);
        a=father[top[a]];
    }
    if(deep[a]>deep[b])swap(a,b);
    return a;
}
inline long long dist(long long x,long long y){
    return dis[x]+dis[y]-(dis[lca(x,y)]*2);
}
inline long long d(long long x,long long y,long long z){
    return dist(x,y)+dist(x,z)-dist(y,z);
}
set<long long>dfns;
set<long long>::iterator itr;
int main(){
    long long n,m,u,v,w,t,nowans=0;
    cin>>n>>m;
    for(register long long i=1;i<n;++i){
        cin>>u>>v>>w;
        add(u,v,w);
    }
    dfs1(1,0);
    dfs2(1,1);
    for(register long long i=1;i<=m;++i){
        cin>>t;
        long long x=dfn[t],y,z;
        if(!vis[sq[x]])dfns.insert(x);
        y=sq[(itr=dfns.lower_bound(x))==dfns.begin()?*--dfns.end():*--itr];
		z=sq[(itr=dfns.upper_bound(x))==dfns.end()?*dfns.begin():*itr];
        if(vis[sq[x]])dfns.erase(x);
        x=sq[x];
        if(vis[x])vis[x]=0,nowans-=d(x,y,z);
        else vis[x]=1,nowans+=d(x,y,z);
        cout<<nowans<<endl;
    }
}