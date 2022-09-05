#include<bits/stdc++.h>
#define MAXN 200005
#define Min(a,b) a<b?a:b
using namespace std;
int fcnt,n,m,q,p[MAXN];
multiset<int>s[MAXN];
namespace Tree{
    int head[MAXN],_size[MAXN],father[MAXN],deep[MAXN],top[MAXN],dfn[MAXN],big[MAXN],sq[MAXN];
    int ecnt,nowtime;
    namespace SegmentTree{
        struct node{
            int l,r,minn;
            node operator +(const node &x)const{
                return {l,x.r,min(minn,x.minn)};
            }
        }stree[MAXN<<2],NP={0,0,2147483647};
        #define pushup(now) stree[now]=stree[now<<1]+stree[now<<1|1]
        void build(int now,int l,int r){
            if(l==r){
                stree[now]={l,l,p[sq[l]]};
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
        void modify(int now,int k,int v){
            if(stree[now].l==stree[now].r&&stree[now].l==k){
                stree[now].minn=v;
                return;
            }
            if(stree[now].l>k||stree[now].r<k)return;
            modify(now<<1,k,v),modify(now<<1|1,k,v);
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
    inline SegmentTree::node tree_query(int a,int b){
        SegmentTree::node ans=SegmentTree::NP;
        while(top[a]!=top[b]){
            if(deep[top[a]]<deep[top[b]])swap(a,b);
            ans=ans+SegmentTree::query(1,dfn[top[a]],dfn[a]);
            a=father[top[a]];
        }
        if(deep[a]>deep[b])swap(a,b);
        ans=ans+SegmentTree::query(1,dfn[a],dfn[b]);
        if(a>n)ans.minn=min(ans.minn,p[father[a]]);
        return ans;
    }
    inline void init(){
        dfs1(1,0);
        dfs2(1,1);
        for(register int i=1;i<=n;++i)
            if(father[i])
                s[father[i]].insert(p[i]);
        for(register int i=n+1;i<=fcnt;++i)
            p[i]=*s[i].begin();
        SegmentTree::build(1,1,fcnt);
    }
}
namespace Tarjan{
    int head[MAXN],dfn[MAXN],low[MAXN];
    int nowtime,root,ecnt;
    struct mystack{
        int values[MAXN],top=0;
        inline void push(int x){
            values[top++]=x;
        }
        inline int pop(){
            return values[--top];
        }
    }s;
    struct edge{
        int to,next;
    }e[MAXN<<1];
    inline void add(int u,int v){
        e[++ecnt]={v,head[u]},head[u]=ecnt;
        e[++ecnt]={u,head[v]},head[v]=ecnt;
    }
    inline void tarjan(int x){
        dfn[x]=low[x]=++nowtime;
        s.push(x);
        for(register int i=head[x];i;i=e[i].next){
            int v(e[i].to);
            if(!dfn[v]){
                tarjan(v);
                low[x]=Min(low[x],low[v]);
                if(low[v]>=dfn[x]){ 
                    ++fcnt;
                    int k;
                    do{
                        k=s.pop();
                        Tree::add(fcnt,k);
                    }while(k!=v);
                    Tree::add(fcnt,x);
                }
            }else low[x]=Min(low[x],dfn[v]);
        }
    }
    inline void search(){
        fcnt=n;
        for(register int i=1;i<=n;++i)
            if(!dfn[i]){
                root=i;
                tarjan(i);
            }
    }
}
int main(){
    char opt;
    int u,v,from,to;
    cin>>n>>m>>q;
    for(register int i=1;i<=n;++i)cin>>p[i];
    for(register int i=1;i<=m;++i){
        cin>>u>>v;
        Tarjan::add(u,v);
    }
    Tarjan::search();
    Tree::init();
    while(q--){
        cin>>opt>>from>>to;
        if(opt=='C'){
            Tree::SegmentTree::modify(1,Tree::dfn[from],to);
            if(Tree::father[from]){
                s[Tree::father[from]].erase(s[Tree::father[from]].find(p[from]));
                s[Tree::father[from]].insert(to);
                if(p[Tree::father[from]]!=*s[Tree::father[from]].begin()){
                    p[Tree::father[from]]=*s[Tree::father[from]].begin();
                    Tree::SegmentTree::modify(1,Tree::dfn[Tree::father[from]],p[Tree::father[from]]);
                }
            }
            p[from]=to;
        }else cout<<Tree::tree_query(from,to).minn<<endl;
    }
}