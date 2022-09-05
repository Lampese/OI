#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int values[MAXN],head[MAXN],_size[MAXN],father[MAXN],deep[MAXN],top[MAXN],dfn[MAXN],big[MAXN],sq[MAXN];
int n,m,ecnt,nowtime;
namespace st{
    struct node{
        int l,r,sum;
        node operator +(const node &x)const{
           return {l,x.r,sum^x.sum};
        }
    }stree[MAXN<<2];
    #define pushup(now) stree[now]=stree[now<<1]+stree[now<<1|1]
    void build(int now,int l,int r){
        if(l==r){
            stree[now]={l,l,values[sq[l]]};
            return;
        }
        int mid=(l+r)>>1;
        build(now<<1,l,mid);
        build(now<<1|1,mid+1,r);
        pushup(now);
    }
    int query(int now,int l,int r){
        if(stree[now].l>=l&&stree[now].r<=r)return stree[now].sum;
        if(stree[now].l>r||stree[now].r<l)return 0;
        return query(now<<1,l,r)^query(now<<1|1,l,r);
    }
    void change(int now,int k,int v){
        if(stree[now].l==stree[now].r){
            stree[now].sum=v;
            return;
        }
        int mid=(stree[now].l+stree[now].r)>>1;
        if(k<=mid)change(now<<1,k,v);
        else change(now<<1|1,k,v);
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
inline int tree_query(int a,int b){
    int ans=0;
    while(top[a]!=top[b]){
        if(deep[top[a]]<deep[top[b]])swap(a,b);
        ans^=st::query(1,dfn[top[a]],dfn[a]);
        a=father[top[a]];
    }
    if(deep[a]>deep[b])swap(a,b);
    ans^=st::query(1,dfn[a],dfn[b]);
    return ans;
}
int main(){
    int opt,u,v,x,y;
    read(n),read(m);
    for(register int i=1;i<=n;++i)read(values[i]);
    for(register int i=1;i<n;++i){
        read(u),read(v);
        add(u,v);
    }
    dfs1(1,0);
    dfs2(1,1);
    st::build(1,1,n);
    for(register int i=1;i<=m;++i){
        read(opt),read(x),read(y);
        if(opt==1)st::change(1,dfn[x],y);
        else cout<<tree_query(x,y)<<endl;
    }
}