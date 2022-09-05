#include<bits/stdc++.h>
using namespace std;
#define MAXN 300005
#define MAXM 1000005
#define pushup(now) tree[now]=tree[now<<1]+tree[now<<1|1]
#define IN getchar()
#define OUT(_ch) putchar(_ch)
template<typename T>inline void read(T &x){
	x=0;
	char ch=IN;
	while(ch<47)ch=IN;
	while(ch>47)x=(x<<1)+(x<<3)+(ch^48),ch=IN;
}
template<typename T>void P(T x){
	if(x>9)P(x/10);
	OUT(x%10+48);
}
long long arr[MAXN];
struct node{
    long long l,r,maxx,sum;
    node operator+(const node &x)const{
        return {l,x.r,max(maxx,x.maxx),sum+x.sum};
    }
}tree[MAXN<<2],NP={0,0,-1,0};
long long prime[MAXM],D[MAXM],a[MAXM],tot;
bitset<MAXM>vis;
void GetD(long long N){
    vis[1]=D[1]=a[1]=1;
    for(long long i=2;i<=N;++i){
        if(!vis[i])prime[++tot]=i,D[i]=2,a[i]=1;
        for(long long j=1;j<=tot&&i*prime[j]<=N;++j){
            vis[i*prime[j]]=1;
            if(!(i%prime[j])){
                D[i*prime[j]]=D[i]/(a[i]+1)*(a[i]+2);
                a[i*prime[j]]=a[i]+1;
                break;
            }
            D[i*prime[j]]=D[i]*D[prime[j]];
            a[i*prime[j]]=1;
        }
    }
}
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
node query(long long now,long long x,long long y){
    if(x>tree[now].r||y<tree[now].l)return NP;
    else if(x<=tree[now].l&&y>=tree[now].r)return tree[now];
    else return query(now<<1,x,y)+query(now<<1|1,x,y);
}
void rebuild(long long now,long long x,long long y){
    if(x==y){
        tree[now]={x,x,D[arr[x]],D[arr[x]]};
        arr[x]=D[arr[x]];
        return;
    }
    long long mid=(x+y)>>1;
    rebuild(now<<1,x,mid);
    rebuild(now<<1|1,mid+1,y);
    pushup(now);
}
void modify(long long now,long long x,long long y){
    if(x>tree[now].r||y<tree[now].l)return;
    else if(x<=tree[now].l&&y>=tree[now].r){
        if(tree[now].maxx<=2)return;
        rebuild(now,tree[now].l,tree[now].r);
        return;
    }
    else modify(now<<1,x,y),modify(now<<1|1,x,y);
    pushup(now);
}
signed main(){
    GetD(1000005);
    long long n,m,opt,l,r;
    read(n),read(m);
    for(register long long i=1;i<=n;++i)cin>>arr[i];
    build(1,1,n);
    for(register long long i=1;i<=m;++i){
        read(opt),read(l),read(r);
        if(opt==1)modify(1,l,r);
        else P(query(1,l,r).sum),OUT('\n');
    }
}