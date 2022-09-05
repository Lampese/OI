#include<bits/stdc++.h>
using namespace std;
#define MAXN 500005
#define IN stdin->_IO_read_ptr<stdin->_IO_read_end?*stdin->_IO_read_ptr++:__uflow(stdin)
inline void read(int &x){
	x=0;
	char ch=IN;
	while(ch<47)ch=IN;
	while(ch>47)x=(x<<1)+(x<<3)+(ch^48),ch=IN;
}
int head[MAXN],_size[MAXN],father[MAXN],deep[MAXN],top[MAXN],dfn[MAXN],big[MAXN];
int n,m,r,p,ecnt,nowtime;
struct edge{
    int to,next;
}e[MAXN<<1];
inline void add(int u,int v){
    e[++ecnt]={v,head[u]},head[u]=ecnt;
    e[++ecnt]={u,head[v]},head[v]=ecnt;
}
void dfs1(int now,int fa){
    _size[now]=1,father[now]=fa,deep[now]=deep[fa]+1;
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
inline int tree_query(int a,int b){
    int ans=0;
    while(top[a]!=top[b]){
        if(deep[top[a]]<deep[top[b]])swap(a,b);
        ans+=(dfn[a]-dfn[top[a]]+1);
        a=father[top[a]];
    }
    if(deep[a]>deep[b])swap(a,b);
    ans+=dfn[b]-dfn[a];
    return ans;
}
inline int lca(int a,int b){
    while(top[a]!=top[b]){
        if(deep[top[a]]<deep[top[b]])swap(a,b);
        a=father[top[a]];
    }
    if(deep[a]>deep[b])swap(a,b);
    return a;
}
inline int cost(int x,int y,int z,int p){
    return tree_query(x,p)+tree_query(y,p)+tree_query(z,p);
}
int main(){
    int n,m,u,v,x,y,z;
    read(n),read(m);
    for(register int i=1;i<n;++i){
        read(u),read(v);
        add(u,v);
    }
    dfs1(1,0);
    dfs2(1,1);
    for(register int i=1;i<=m;++i){
        read(x),read(y),read(z);
        set<pair<int,int>>LCA;
        int p1=lca(x,y),p2=lca(x,z),p3=lca(y,z);
        LCA.insert({cost(x,y,z,p1),p1});
        LCA.insert({cost(x,y,z,p2),p2});
        LCA.insert({cost(x,y,z,p3),p3});
        cout<<LCA.begin()->second<<" "<<LCA.begin()->first<<endl;
    }
}