#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int values[MAXN],head[MAXN],_size[MAXN],father[MAXN],deep[MAXN],top[MAXN],dfn[MAXN],big[MAXN],sq[MAXN];
int n,m,r,p,ecnt,nowtime;
namespace st{
    struct node{
        int l,r,maxx,tag,len;
        node operator +(const node &x)const{
           return {l,x.r,max(maxx,x.maxx),0,len+x.len};
        }
    }stree[MAXN<<2],NP={0,0,-1,0,0};
    #define pushup(now) stree[now]=stree[now<<1]+stree[now<<1|1]
    inline void givetag(int now,int tag){
        if(stree[now].l==stree[now].r){
            stree[now].maxx+=tag;
            return;
        }
        stree[now].tag+=tag;
        stree[now].maxx+=tag;
    }
    inline void pushdown(int now){
        givetag(now<<1,stree[now].tag);
        givetag(now<<1|1,stree[now].tag);
        stree[now].tag=0;
    }
    void build(int now,int l,int r){
        if(l==r){
            stree[now]={l,l,values[sq[l]],0,1};
            return;
        }
        int mid=(l+r)>>1;
        build(now<<1,l,mid);
        build(now<<1|1,mid+1,r);
        pushup(now);
    }
    node query(int now,int l,int r){
        if(stree[now].tag)pushdown(now);
        if(stree[now].l>=l&&stree[now].r<=r)return stree[now];
        if(stree[now].l>r||stree[now].r<l)return NP;
        return (query(now<<1,l,r)+query(now<<1|1,l,r));
    }
    void change(int now,int l,int r,int v){
        if(stree[now].tag)pushdown(now);
        if(stree[now].l>=l&&stree[now].r<=r){
            givetag(now,v);
            return;
        }
        else if(stree[now].l>r||stree[now].r<l)return;
        else{
            change(now<<1,l,r,v);
            change(now<<1|1,l,r,v);
        }
        pushup(now);
    }
}
struct edge{
    int to,next;
}e[MAXN<<1];
inline void read(int &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
}
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
    top[now]=fa,dfn[now]=++nowtime,sq[nowtime]=now;
    if(big[now])dfs2(big[now],fa);
    for(register int i=head[now];i;i=e[i].next){
        int v(e[i].to);
        if(v==father[now]||v==big[now])continue;
        dfs2(v,v);
    }
}
inline void tree_update(int a,int b,int v){
    while(top[a]!=top[b]){
        if(deep[top[a]]<deep[top[b]])swap(a,b);
        st::change(1,dfn[top[a]],dfn[a],v);
        a=father[top[a]];
    }
    if(deep[a]>deep[b])swap(a,b);
    st::change(1,dfn[a],dfn[b],v);
}
int main(){
    int opt,u,v,x,y;
    read(n),read(m);
    for(register int i=1;i<n;++i){
        read(u),read(v);
        add(u,v);
    }
    dfs1(1,0);
    dfs2(1,1);
    st::build(1,1,n);
    for(register int i=1;i<=m;++i){
        read(x),read(y);
        tree_update(x,y,1);
    }
    cout<<st::query(1,dfn[1],dfn[1]+_size[1]-1).maxx;
}