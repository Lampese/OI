#include<bits/stdc++.h>
#define MAXN 100005
#define pushup(now) tree[now]=tree[now<<1]+tree[now<<1|1]
using namespace std;
long long n,m,arr[MAXN];
struct node{
    long long l,r,maxx,sum;
    node operator+(const node &x)const{
        return {l,x.r,max(maxx,x.maxx),sum+x.sum};
    }
}tree[MAXN<<2],NP_NODE={0,0,-1,0};
void build(long long now,long long l,long long r){
    if(l==r){
        tree[now]={l,l,arr[l],arr[l]};
        return;
    }
    long long mid=(l+r)>>1;
    build(now<<1,l,mid);
    build(now<<1|1,mid+1,r);
    pushup(now);
}
node query(long long now,long long l,long long r){
    if(tree[now].l>r||tree[now].r<l)return NP_NODE;
    if(tree[now].l>=l&&tree[now].r<=r)return tree[now];
    else return query(now<<1,l,r)+query(now<<1|1,l,r);
}
void inline_mod(long long now,long long p){
    if(tree[now].maxx<p)return;
    if(tree[now].l==tree[now].r){
        tree[now].maxx%=p;
        tree[now].sum%=p;
        return;
    }
    inline_mod(now<<1,p),inline_mod(now<<1|1,p);
    pushup(now);
}
void mod(long long now,long long l,long long r,long long p){
    if(tree[now].l>r||tree[now].r<l)return;
    if(tree[now].maxx<p)return;
    if(tree[now].l>=l&&tree[now].r<=r){
        inline_mod(now,p);
        return;
    }
    else mod(now<<1,l,r,p),mod(now<<1|1,l,r,p);
    pushup(now);
}
void modify(long long now,long long k,long long v){
    if(tree[now].l==tree[now].r&&tree[now].l==k){
        tree[now].maxx=tree[now].sum=v;
        return;
    }
    long long mid=(tree[now].l+tree[now].r)>>1;
    if(k<=mid)modify(now<<1,k,v);
    else modify(now<<1|1,k,v);
    pushup(now);
}
signed main(){
    long long opt,l,r,v;
    cin>>n>>m;
    for(register long long i=1;i<=n;++i)cin>>arr[i];
    build(1,1,n);
    while(m--){
        cin>>opt;
        if(opt==1){
            cin>>l>>r;
            cout<<query(1,l,r).sum<<endl;
        }else if(opt==2){
            cin>>l>>r>>v;
            mod(1,l,r,v);
        }else if(opt==3){
            cin>>l>>v;
            modify(1,l,v);
        }
    }
}