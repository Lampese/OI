#include<bits/stdc++.h>
#define MAXN 200005
#define pushup(now) tree[now]=tree[now<<1]+tree[now<<1|1]
using namespace std;
int n,m;
struct node{
    int l,r,v;
    bool tag;
    node operator+(const node &x)const{
        return {l,x.r,v+x.v,0};
    }
}tree[MAXN<<2],NP={0,0,0,0};
inline void givetag(int now){
    if(tree[now].l==tree[now].r){
        if(tree[now].v==1)tree[now].v=0;
        else tree[now].v=1;
    }else{
        tree[now].tag=!tree[now].tag;
        tree[now].v=((tree[now].r-tree[now].l+1)-tree[now].v);
    }
}
inline void pushdown(int now){
    givetag(now<<1);
    givetag(now<<1|1);
    tree[now].tag=false;
}
void build(int now,int l,int r){
    if(l==r){
        tree[now]={l,l,0,0};
        return;
    }
    int mid=(l+r)>>1;
    build(now<<1,l,mid);
    build(now<<1|1,mid+1,r);
    pushup(now);
}
void modify(int now,int l,int r){
    if(tree[now].tag)pushdown(now);
    if(tree[now].l>r||tree[now].r<l)return;
    if(l<=tree[now].l&&tree[now].r<=r){
        givetag(now);
        return;
    }else modify(now<<1,l,r),modify(now<<1|1,l,r);
    pushup(now);
}
node query(int now,int l,int r){
    if(tree[now].tag)pushdown(now);
    if(tree[now].l>r||tree[now].r<l)return NP;
    if(l<=tree[now].l&&tree[now].r<=r)return tree[now];
    return query(now<<1,l,r)+query(now<<1|1,l,r);
}
int main(){
    int opt,l,r;
    cin>>n>>m;
    build(1,1,n);
    while(m--){
        cin>>opt>>l>>r;
        if(opt==0)modify(1,l,r);
        else cout<<query(1,l,r).v<<endl;
    }
}