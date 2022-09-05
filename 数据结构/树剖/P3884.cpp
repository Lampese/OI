#include<bits/stdc++.h> 
#define MAXN 105
using namespace std;
int head[MAXN],_size[MAXN],father[MAXN],deep[MAXN],top[MAXN],dfn[MAXN],big[MAXN],wei[MAXN];
int n,u,v,p,ecnt,nowtime,dep,mwei;
struct edge{
    int to,next;
}e[MAXN<<1];
inline void add(int u,int v){
    e[++ecnt]={v,head[u]},head[u]=ecnt;
    e[++ecnt]={u,head[v]},head[v]=ecnt;
}
void dfs1(int now,int fa){
    _size[now]=1,father[now]=fa,deep[now]=deep[fa]+1;
    ++wei[deep[now]];
    mwei=max(mwei,wei[deep[now]]);
    dep=max(dep,deep[now]);
    for(register int i=head[now];i;i=e[i].next){
        int v(e[i].to);
        if(v==fa)continue;
        dfs1(v,now);
        _size[now]+=_size[v];
        if(big[now]==0||_size[big[now]]<_size[v])big[now]=v;
    }
}
void dfs2(int now,int fa){
    top[now]=fa,dfn[now]=++nowtime;
    if(big[now])dfs2(big[now],fa);
    for(register int i=head[now];i;i=e[i].next){
        int v(e[i].to);
        if(v==father[now]||v==big[now])continue;
        dfs2(v,v);
    }
}
inline int lca(int a,int b){
    while(top[a]!=top[b]){
        if(deep[top[a]]<deep[top[b]])swap(a,b);
        a=father[top[a]];
    }
    if(deep[a]>deep[b])swap(a,b);
    return a;
}
int main(){
    cin>>n;
    for(register int i=1;i<n;++i){
        cin>>u>>v;
        add(u,v);
    }
    dfs1(1,0);
    dfs2(1,1);
    cout<<dep<<endl<<mwei<<endl;
    int u,v;
    cin>>u>>v;
    int aa=lca(u,v),ans=0;
    while(u!=aa){
        u=father[u];
        ans+=2;
    }
    while(v!=aa){
        v=father[v];
        ++ans;
    }
    cout<<ans<<endl;
}