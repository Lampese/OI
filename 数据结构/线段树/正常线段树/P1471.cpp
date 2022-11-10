#include<bits/stdc++.h>
#define pushup(now) tree[now]=tree[now<<1]+tree[now<<1|1]
#define MAXN 100005
using namespace std;
int n,m;
const double eps=1e-10;
double a[MAXN];
struct node{
    int l,r;
    double sum,sqrt;
    int len;
    double tag;
    node operator +(const node &x)const{
        return {l,x.r,sum+x.sum,sqrt+x.sqrt,len+x.len,0};
    }
}tree[MAXN<<2],NP={0,0,0,0,0,0};
inline void build(int now,int l,int r){
    if(l==r){
        tree[now]={l,l,a[l],a[l]*a[l],1,0};
        return;
    }
    int mid=(l+r)>>1;
    build(now<<1,l,mid);
    build(now<<1|1,mid+1,r);
    pushup(now);
}
inline void givetag(int now,double tag){
    if(tree[now].l==tree[now].r){
        tree[now]={tree[now].l,tree[now].l,tree[now].sum+tag,(tree[now].sum+tag)*(tree[now].sum+tag),1,0};
        return;
    }
    tree[now].sqrt+=(2*tree[now].sum*tag)+(tree[now].len*tag*tag);
    tree[now].sum+=(tag*tree[now].len);
    tree[now].tag+=tag;
}
inline void pushdown(int now){
    givetag(now<<1,tree[now].tag);
    givetag(now<<1|1,tree[now].tag);
    tree[now].tag=0;
}
inline void modify(int now,int l,int r,double k){
    if(fabs(tree[now].tag)>eps)pushdown(now);
    if(tree[now].l>r||tree[now].r<l)return;
    if(l<=tree[now].l&&tree[now].r<=r){
        givetag(now,k);
        return;
    }else modify(now<<1,l,r,k),modify(now<<1|1,l,r,k);
    pushup(now);
}
inline node query(int now,int l,int r){
    if(fabs(tree[now].tag)>eps)pushdown(now);
    if(tree[now].l>r||tree[now].r<l)return NP;
    if(l<=tree[now].l&&tree[now].r<=r)return tree[now];
    return query(now<<1,l,r)+query(now<<1|1,l,r);
}
int main(){
    cin>>n>>m;
    for(register int i=1;i<=n;++i)cin>>a[i];
    build(1,1,n);
    while(m--){
        int opt,l,r;
        double k;
        cin>>opt>>l>>r;
        if(opt==1){
            cin>>k;
            modify(1,l,r,k);
        }else if(opt==2){
            auto result=query(1,l,r);
            printf("%.4lf\n",(result.sum/result.len));
        }else{
            auto result=query(1,l,r);
            double average=result.sum/result.len;
            printf("%.4lf\n",(result.sqrt-2*result.sum*average+average*average*result.len)/result.len);
        }
    }
}