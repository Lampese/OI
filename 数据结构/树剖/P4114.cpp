#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int values[MAXN],head[MAXN],_size[MAXN],father[MAXN],deep[MAXN],top[MAXN],dfn[MAXN],big[MAXN],sq[MAXN],from[MAXN],to[MAXN];
int n,ecnt,nowtime;
namespace st{
    struct node{
        int l,r,len,maxx;
        node operator +(const node &x)const{
           return {l,x.r,len+x.len,max(maxx,x.maxx)};
        }
    }stree[MAXN<<2],NP={0,0,0,-2147483647};
    #define pushup(now) stree[now]=stree[now<<1]+stree[now<<1|1]
    void build(int now,int l,int r){
        if(l==r){
            stree[now]={l,l,1,values[sq[l]]};
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
    void update(int now,int k,int v){
        if(stree[now].l==stree[now].r){
            stree[now].maxx=v;
            return;
        }
        int mid=(stree[now].l+stree[now].r)>>1;
        if(k<=mid)update(now<<1,k,v);
        else update(now<<1|1,k,v);
        pushup(now);
    }
}
struct edge{
    int to,next,w;
}e[MAXN<<1];
inline void read(int &x){
	x=0;
    int w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
        if(ch=='-')w=-1;
        ch=getchar();
    }
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
    x*=w;
}
inline void add(int u,int v,int w){
    e[++ecnt]={v,head[u],w},head[u]=ecnt;
    e[++ecnt]={u,head[v],w},head[v]=ecnt;
}
void dfs1(int now,int fa){
    _size[now]=1,father[now]=fa,deep[now]=deep[fa]+1;
    for(register int i=head[now];i;i=e[i].next){
        int v(e[i].to);
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
        int v(e[i].to);
        if(v==father[now]||v==big[now])continue;
        dfs2(v,v);
    }
}
inline st::node tree_query(int a,int b){
    st::node ans=st::NP;
    while(top[a]!=top[b]){
        if(deep[top[a]]<deep[top[b]])swap(a,b);
        ans=ans+st::query(1,dfn[top[a]],dfn[a]);
        a=father[top[a]];
    }
    if(deep[a]>deep[b])swap(a,b);
    ans=ans+st::query(1,dfn[a]+1,dfn[b]);
    return ans;
}
int main(){
    int w,x,y;
    string opt;
    read(n);
    for(register int i=1;i<n;++i){
        read(from[i]),read(to[i]),read(w);
        add(from[i],to[i],w);
    }
    dfs1(1,0);
    dfs2(1,1);
    st::build(1,1,n);
    while(true){
        cin>>opt;
        if(opt[0]=='D')return 0;
        read(x),read(y);
        if(opt[0]=='Q')
            if(x==y)printf("0\n");
            else printf("%d\n",tree_query(x,y).maxx);
        else st::update(1,max(dfn[from[x]],dfn[to[x]]),y);
    }
}