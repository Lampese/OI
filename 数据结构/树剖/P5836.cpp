#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
string values;
int head[MAXN],_size[MAXN],father[MAXN],deep[MAXN],top[MAXN],dfn[MAXN],big[MAXN],sq[MAXN];
int n,m,ecnt,nowtime;
namespace st{
    struct node{
        int l,r;
        bool L1=false,L2=false;
        node operator +(const node &x)const{
           return {l,x.r,L1||x.L1,L2||x.L2};
        }
    }stree[MAXN<<2],NP={0,0,0,0};
    #define pushup(now) stree[now]=stree[now<<1]+stree[now<<1|1]
    void build(int now,int l,int r){
        if(l==r){
            stree[now]={l,l,values[sq[l]]=='H',values[sq[l]]=='G'};
            return;
        }
        int mid=(l+r)>>1;
        build(now<<1,l,mid);
        build(now<<1|1,mid+1,r);
        pushup(now);
    }
    node query(int now,int l,int r){
        if(stree[now].l>=l&&stree[now].r<=r)return stree[now];
        if(stree[now].l>r||stree[now].r<l)return NP;
        return query(now<<1,l,r)+query(now<<1|1,l,r);
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
inline st::node tree_query(int a,int b){
    st::node ans=st::NP;
    while(top[a]!=top[b]){
        if(deep[top[a]]<deep[top[b]])swap(a,b);
        ans=ans+st::query(1,dfn[top[a]],dfn[a]);
        a=father[top[a]];
    }
    if(deep[a]>deep[b])swap(a,b);
    ans=ans+st::query(1,dfn[a],dfn[b]);
    return ans;
}
int main(){
    char opt;
    int u,v;
    cin>>n>>m>>values;
    values=","+values;
    for(register int i=1;i<n;++i){
        cin>>u>>v;
        add(u,v);
    }
    dfs1(1,0);
    dfs2(1,1);
    st::build(1,1,n);
    for(register int i=1;i<=m;++i){
        cin>>u>>v>>opt;
        auto result=tree_query(u,v);
        if(result.L1&&opt=='H'){
            cout<<1;
        }else if(result.L2&&opt=='G'){
            cout<<1;
        }else cout<<0;
    }    
}