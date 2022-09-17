#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int head[MAXN],_size[MAXN],father[MAXN],deep[MAXN],top[MAXN],dfn[MAXN],big[MAXN],sq[MAXN];
int n,m,ecnt,nowtime;
namespace st{
    #define pushup(now) tree[now]=tree[now<<1]+tree[now<<1|1]
    struct node{
        int l,r,val,len,tag;
        node operator+(const node &x)const{
            return {l,x.r,val+x.val,len+x.len,114514};
        }
    }tree[MAXN<<2],NP={0,0,0,0,114514};
    inline void givetag(int now,int tag){
        if(tree[now].l==tree[now].r){
            tree[now].val=tag;
            return;
        }
        if(tree[now].tag!=tag){
            tree[now].tag=tag;
            tree[now].val=tree[now].len*tag;
        }
    }
    inline void pushdown(int now){
        givetag(now<<1,tree[now].tag);
        givetag(now<<1|1,tree[now].tag);
        tree[now].tag=114514;
    }
    void build(int now,int l,int r){
        if(l==r){
            tree[now]={l,l,0,1,114514};
            return;
        }
        int mid=(l+r)>>1;
        build(now<<1,l,mid);
        build(now<<1|1,mid+1,r);
        pushup(now);
    }
    node query(int now,int l,int r){
        if(tree[now].tag!=114514)pushdown(now);
        if(tree[now].l>=l&&tree[now].r<=r)return tree[now];
        if(tree[now].l>r||tree[now].r<l)return NP;
        return query(now<<1,l,r)+query(now<<1|1,l,r);
    }
    void modify(int now,int l,int r,int v){
        if(tree[now].tag!=114514)pushdown(now);
        if(tree[now].l>=l&&tree[now].r<=r){
            givetag(now,v);
            return;
        }
        else if(tree[now].l>r||tree[now].r<l)return;
        else{
            modify(now<<1,l,r,v),modify(now<<1|1,l,r,v);
        }
        pushup(now);
    }
}
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
inline void tree_update(int a,int b,int v){
    while(top[a]!=top[b]){
        if(deep[top[a]]<deep[top[b]])swap(a,b);
        st::modify(1,dfn[top[a]],dfn[a],v);
        a=father[top[a]];
    }
    if(deep[a]>deep[b])swap(a,b);
    st::modify(1,dfn[a],dfn[b],v);
}
inline st::node child_tree_query(int a){
    return st::query(1,dfn[a],dfn[a]+_size[a]-1);
}
inline void child_tree_update(int a,int v){
    st::modify(1,dfn[a],dfn[a]+_size[a]-1,v);
}
int main(){
    string opt;
    int temp;
    cin>>n;
    for(register int i=2;i<=n;++i){
        cin>>temp;
        ++temp;
        add(temp,i);
    }
    dfs1(1,0);
    dfs2(1,1);
    st::build(1,1,nowtime);
    cin>>m;
    for(register int i=1;i<=m;++i){
        cin>>opt;
        int l=st::tree[1].val;
        if(opt=="install"){
            cin>>temp;
            ++temp;
            tree_update(1,temp,1);
            cout<<abs(st::tree[1].val-l)<<endl;;
        }else{
            cin>>temp;
            ++temp;
            child_tree_update(temp,0);
            cout<<abs(st::tree[1].val-l)<<endl;
        }
    }
}