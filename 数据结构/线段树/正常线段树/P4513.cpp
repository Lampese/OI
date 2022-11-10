#include<bits/stdc++.h>
using namespace std;
#define MAXN 500005
#define pushup(now) tree[now]=tree[now<<1]+tree[now<<1|1]
int n,m,arr[MAXN];
struct node{
    int l,r,maxl,maxr,maxa,sum;
    node operator +(const node &x)const{
        return {l,x.r,max(maxl,sum+x.maxl),max(x.maxr,maxr+x.sum),max(max(maxa,x.maxa),maxr+x.maxl),sum+x.sum};
    }
}tree[MAXN<<2];
inline void build(int now,int l,int r){
    if(l==r){
        tree[now]={l,l,arr[l],arr[l],arr[l],arr[l]};
        return;
    }
    int mid=(l+r)>>1;
    build(now<<1,l,mid);
    build(now<<1|1,mid+1,r);
    pushup(now);
}
inline void modify(int now,int k,int s){
    if(tree[now].l==tree[now].r&&tree[now].l==k){
        tree[now]={tree[now].l,tree[now].l,s,s,s,s};
        return;
    }
    int mid=(tree[now].l+tree[now].r)>>1;
    if(k<=mid)modify(now<<1,k,s);
    else modify(now<<1|1,k,s);
    pushup(now);
}
inline node query(int now,int l,int r){
    if(l<=tree[now].l&&tree[now].r<=r)return tree[now];
    int mid=(tree[now].l+tree[now].r)>>1;
    if(r<=mid)return query(now<<1,l,r);
    if(l>mid)return query(now<<1|1,l,r);
    return query(now<<1,l,r)+query(now<<1|1,l,r);
}
int main(){
    cin>>n>>m;
    for(register int i=1;i<=n;++i)cin>>arr[i];
    build(1,1,n);
    while(m--){
        int k,a,b;
        cin>>k>>a>>b;
        if(k==1){
            if(a>b)swap(a,b);
            cout<<query(1,a,b).maxa<<endl;
        }else modify(1,a,b);
    }
}