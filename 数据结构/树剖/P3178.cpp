#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
long long values[MAXN],head[MAXN],_size[MAXN],father[MAXN],deep[MAXN],top[MAXN],dfn[MAXN],big[MAXN],sq[MAXN];
long long n,m,ecnt,nowtime;
namespace st{
    struct node{
        long long l,r,sum,tag,len;
        node operator +(const node &x)const{
           return {l,x.r,(sum+x.sum),0,len+x.len};
        }
    }stree[MAXN<<2];
    #define pushup(now) stree[now]=stree[now<<1]+stree[now<<1|1]
    inline void givetag(long long now,long long tag){
        if(stree[now].l==stree[now].r){
            stree[now].sum+=tag;
            return;
        }
        stree[now].tag+=tag;
        stree[now].sum+=stree[now].len*tag;
    }
    inline void pushdown(long long now){
        givetag(now<<1,stree[now].tag);
        givetag(now<<1|1,stree[now].tag);
        stree[now].tag=0;
    }
    void build(long long now,long long l,long long r){
        if(l==r){
            stree[now]={l,l,values[sq[l]],0,1};
            return;
        }
        long long mid=(l+r)>>1;
        build(now<<1,l,mid);
        build(now<<1|1,mid+1,r);
        pushup(now);
    }
    long long query(long long now,long long l,long long r){
        if(stree[now].tag)pushdown(now);
        if(stree[now].l>=l&&stree[now].r<=r)return stree[now].sum;
        if(stree[now].l>r||stree[now].r<l)return 0;
        return query(now<<1,l,r)+query(now<<1|1,l,r);
    }
    void change(long long now,long long l,long long r,long long v){
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
    long long to,next;
}e[MAXN<<1];
inline void read(long long &x){
	x=0;
    long long w=1;
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
inline void add(long long u,long long v){
    e[++ecnt]={v,head[u]},head[u]=ecnt;
    e[++ecnt]={u,head[v]},head[v]=ecnt;
}
void dfs1(long long now,long long fa){
    _size[now]=1,father[now]=fa,deep[now]=deep[fa]+1;
    for(register long long i=head[now];i;i=e[i].next){
        long long v(e[i].to);
        if(v==fa)continue;
        dfs1(v,now);
        _size[now]+=_size[v];
        if(big[now]==0||_size[big[now]]<_size[v])big[now]=v;
    }
}
void dfs2(long long now,long long fa){
    top[now]=fa,dfn[now]=++nowtime,sq[nowtime]=now;
    if(big[now])dfs2(big[now],fa);
    for(register long long i=head[now];i;i=e[i].next){
        long long v(e[i].to);
        if(v==father[now]||v==big[now])continue;
        dfs2(v,v);
    }
}
inline long long tree_query(long long a,long long b){
    long long ans=0;
    while(top[a]!=top[b]){
        if(deep[top[a]]<deep[top[b]])swap(a,b);
        ans+=st::query(1,dfn[top[a]],dfn[a]);
        a=father[top[a]];
    }
    if(deep[a]>deep[b])swap(a,b);
    ans+=st::query(1,dfn[a],dfn[b]);
    return ans;
}
inline void child_tree_update(long long a,long long v){
    st::change(1,dfn[a],dfn[a]+_size[a]-1,v);
}
int main(){
    long long opt,u,v,x,y;
    read(n),read(m);
    for(register long long i=1;i<=n;++i)read(values[i]);
    for(register long long i=1;i<n;++i){
        read(u),read(v);
        add(u,v);
    }
    dfs1(1,0);
    dfs2(1,1);
    st::build(1,1,n);
    for(register long long i=1;i<=m;++i){
        read(opt),read(x);
        if(opt==1){
            read(y);
            st::change(1,dfn[x],dfn[x],y);
        }else if(opt==2){
            read(y);
            child_tree_update(x,y);
        }else printf("%lld\n",tree_query(x,1));
    }
}