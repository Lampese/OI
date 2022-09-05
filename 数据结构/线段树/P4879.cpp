#include<bits/stdc++.h>
#define MAXN 500005
using namespace std;
long long ans,n,m,sum,arr[MAXN];
bitset<MAXN>vis;
struct node{
    long long l,r,sum;
    node operator+(const node &x)const{
        return {l,x.r,sum+x.sum};
    }
}tree[MAXN<<2];
#define pushup(now) tree[now]=tree[now<<1]+tree[now<<1|1]
void build(long long now,long long l,long long r){
    if(l==r){
        tree[now]={l,l,(l<=n)};
        return;
    }
    long long mid=(l+r)>>1;
    build(now<<1,l,mid);
    build(now<<1|1,mid+1,r);
    pushup(now);
}
void modify(long long now,long long k,long long val){
    if(tree[now].l==tree[now].r){
        tree[now].sum=val;
        return;
    }
    long long mid=(tree[now].l+tree[now].r)>>1;
    if(k<=mid)modify(now<<1,k,val);
    else modify(now<<1|1,k,val);
    pushup(now);
}
void search(long long now,long long num){
    if(tree[now].l==tree[now].r){
        ans=tree[now].l;
        return;
    }
    if(tree[now<<1].sum>=num)search(now<<1,num);
    else search(now<<1|1,num-tree[now<<1].sum);
}
signed main(){
    cin>>n>>m;
    char opt;
    long long x,y;
    for(register long long i=1;i<=n;++i){
        cin>>arr[i];
        sum+=arr[i];
        vis[i]=true;
    }
    build(1,1,500000);
    while(m--){
        cin>>opt;
        if(opt=='Q')cout<<sum<<endl;
        else if(opt=='C'){
            cin>>x>>y;
            arr[x]-=y;
            sum-=y;
        }else if(opt=='I'){
            cin>>x>>y;
            sum=sum-arr[x]+y;
            modify(1,x,1);
            arr[x]=y;
            vis[x]=true;
        }else if(opt=='D'){
            cin>>x;
            search(1,x);
            modify(1,ans,0);
            sum-=arr[ans];
            arr[ans]=0;
            vis[ans]=false;
        }
    }
}