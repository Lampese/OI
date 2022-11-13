#include<bits/stdc++.h>
#define pushup(now) tree[now]=tree[now<<1]+tree[now<<1|1]
#define MAXN 100005
using namespace std;
int n,m,arr[MAXN];
struct node{
    int l,r,minn;
    node operator +(const node &x)const{
        return {l,x.r,min(minn,x.minn)};
    }
}tree[MAXN<<2],NP={0,0,INT_MAX};
inline void build(int now,int l,int r){
    if(l==r){
        tree[now]={l,l,arr[l]};
        return;
    }
    int mid=(l+r)>>1;
    build(now<<1,l,mid);
    build(now<<1|1,mid+1,r);
    pushup(now);
}
inline node query(int now,int l,int r){
    if(tree[now].l>r||l>tree[now].r)return NP;
    else if(l<=tree[now].l&&tree[now].r<=r)return tree[now];
    else return query(now<<1,l,r)+query(now<<1|1,l,r);
}
int main(){
    cin>>n>>m;
    for(register int i=1;i<=n;++i)cin>>arr[i];
    build(1,1,n);
    while(m--){
        int l,r;
        cin>>l>>r;
        cout<<query(1,l,r).minn<<" ";
    }
}