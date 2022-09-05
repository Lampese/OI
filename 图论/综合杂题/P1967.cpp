#include<bits/stdc++.h>
#define MAXN 10005
#define MAXM 50005
using namespace std;
int fa[MAXN];
int n,m;
struct edge{
    int v,w,next;
}e[MAXM<<1];
struct kedge{
    int u,v,w;
    bool operator <(const kedge &x)const{
        return w>x.w;
    }
}ke[MAXM];
namespace Tree{
    int head[MAXN],values[MAXN],_size[MAXN],father[MAXN],deep[MAXN],top[MAXN],dfn[MAXN],big[MAXN],sq[MAXN];
    int nowtime,ecnt;
    namespace ST{
        struct node{
            int l,r,minn;
            node operator +(const node &x)const{
                return {l,x.r,min(minn,x.minn)};
            }
        }stree[MAXN<<2],NP={0,0,2147483647};
        #define pushup(now) stree[now]=stree[now<<1]+stree[now<<1|1]
        void build(int now,int l,int r){
            if(l==r){
                stree[now]={l,l,values[sq[l]]};
                return;
            }
            int mid=(l+r)>>1;
            build(now<<1,l,mid),build(now<<1|1,mid+1,r);
            pushup(now);
        }
        node query(int now,int l,int r){
            if(stree[now].l>=l&&stree[now].r<=r)return stree[now];
            if(stree[now].l>r||stree[now].r<l)return NP;
            return query(now<<1,l,r)+query(now<<1|1,l,r);
        }
    }
    inline void add(int u,int v,int w){
        e[++ecnt]={v,w,head[u]},head[u]=ecnt;
        e[++ecnt]={u,w,head[v]},head[v]=ecnt;
    }
    void dfs1(int now,int fa){
        _size[now]=1,father[now]=fa,deep[now]=deep[fa]+1;
        for(register int i=head[now];i;i=e[i].next){
            int v(e[i].v);
            if(v==fa)continue;
            values[v]=e[i].w;
            dfs1(v,now);
            _size[now]+=_size[v];
            if(big[now]==0||_size[big[now]]<_size[v])big[now]=v;
        }
    }
    void dfs2(int now,int fa){
        top[now]=fa,dfn[now]=++nowtime,sq[nowtime]=now;
        if(big[now])dfs2(big[now],fa);
        for(register int i=head[now];i;i=e[i].next){
            int v(e[i].v);
            if(v==father[now]||v==big[now])continue;
            dfs2(v,v);
        }
    }
    inline ST::node tree_query(int a,int b){
        ST::node ans=ST::NP;
        while(top[a]!=top[b]){
            if(deep[top[a]]<deep[top[b]])swap(a,b);
            ans=ans+ST::query(1,dfn[top[a]],dfn[a]);
            a=father[top[a]];
        }
        if(deep[a]>deep[b])swap(a,b);
        ans=ans+ST::query(1,dfn[a]+1,dfn[b]);
        return ans;
    }
}
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
inline void kruskal(){
    sort(ke+1,ke+m+1);
    for(register int i=1;i<=m;++i){
        int x=ke[i].u,y=ke[i].v;
        int fx=find(x),fy=find(y);
        if(fx!=fy){
            Tree::add(x,y,ke[i].w);
            fa[fx]=fy;
        }
    }
}   
int main(){
    int u,v,w,q;
    cin>>n>>m;
    for(register int i=1;i<=n;++i)fa[i]=i;
    for(register int i=1;i<=m;++i){
        cin>>u>>v>>w;
        ke[i]={u,v,w};
    }
    kruskal();
    Tree::dfs1(1,0);
    Tree::dfs2(1,1);
    Tree::ST::build(1,1,n);
    cin>>q;
    while(q--){
        cin>>u>>v;
        int fx=find(u),fy=find(v);
        if(fx!=fy)cout<<-1;
        else cout<<Tree::tree_query(u,v).minn;
        cout<<endl;
    }
}