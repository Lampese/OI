#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
long long arr[N];
struct node{
    long long l,r,sum,tag,len;
    node operator +(const node &x)const{
        return {l,x.r,sum+x.sum,0,len+x.len};
    }
}stree[N<<2];
#define pushup(now) stree[now]=stree[now<<1]+stree[now<<1|1]
inline void givetag(int now,int tag){
    if(stree[now].l==stree[now].r){
        stree[now].sum+=tag;
        return;
    }
    stree[now].tag+=tag;
    stree[now].sum+=stree[now].len*tag;
}
inline void pushdown(int now){
    givetag(now<<1,stree[now].tag);
    givetag(now<<1|1,stree[now].tag);
    stree[now].tag=0;
}
void build(int now,int l,int r){
    if(l==r){
        stree[now]={l,l,arr[l],0,1};
        return;
    }
    int mid=(l+r)>>1;
    build(now<<1,l,mid);
    build(now<<1|1,mid+1,r);
    pushup(now);
}
long long query(int now,int l,int r){
    if(stree[now].tag)pushdown(now);
    if(stree[now].l>=l&&stree[now].r<=r)return stree[now].sum;
    if(stree[now].l>r||stree[now].r<l)return 0;
    return query(now<<1,l,r)+query(now<<1|1,l,r);
}
void change(int now,int l,int r,int v){
    if(stree[now].tag)pushdown(now);
    if(stree[now].l>=l&&stree[now].r<=r){
        givetag(now,v);
        return;
    }
    else if(stree[now].l>r||stree[now].r<l)return;
    else{
        change(now<<1,l,r,v);
        change(now<<1|1,l,r,v);
    }
    pushup(now);
}
int main(){
    int n,m,opt;
    cin>>n>>m;
    for(register int i=1;i<=n;++i)cin>>arr[i];
    build(1,1,n);
    for(register int i=1;i<=m;++i){
        cin>>opt;
        if(opt==1){
            long long l,r,v;
            cin>>l>>r>>v;
            change(1,l,r,v);
        }else{
            int l,r;
            cin>>l>>r;
            cout<<query(1,l,r)<<endl;
        }
    }
    return 0;
}