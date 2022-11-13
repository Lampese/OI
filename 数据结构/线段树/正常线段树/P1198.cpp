#include<bits/stdc++.h>
#define int long long
#define MAXN 200005
#define pushup(now) tree[now]=tree[now<<1]+tree[now<<1|1]
using namespace std;
int m,d,t,now;
struct node{
    int l,r,maxx;
    node operator +(const node &x)const{
        return {l,x.r,max(maxx,x.maxx)};
    }
}tree[MAXN<<2],NP={0,0,LONG_LONG_MIN};
inline void build(int now,int l,int r){
    if(l==r){
        tree[now]={l,l,LONG_LONG_MIN};
        return;
    }
    int mid=(l+r)>>1;
    build(now<<1,l,mid);
    build(now<<1|1,mid+1,r);
    pushup(now);
}
inline void modify(int now,int p,int v){
    if(tree[now].l==tree[now].r){
        tree[now].maxx=v;
        return;
    }
    int mid=(tree[now].l+tree[now].r)>>1;
    if(p<=mid)modify(now<<1,p,v);
    else modify(now<<1|1,p,v);
    pushup(now);
}
inline node query(int now,int l,int r){
    if(tree[now].l>r||l>tree[now].r)return NP;
    else if(l<=tree[now].l&&tree[now].r<=r)return tree[now];
    else return query(now<<1,l,r)+query(now<<1|1,l,r);
}
signed main(){
    cin>>m>>d;
    build(1,1,m);
    while(m--){
        int x;
        char opt;
        cin>>opt>>x;
        if(opt=='Q'){
            t=query(1,now-x+1,now).maxx;
            cout<<t<<endl;
        }else{
            ++now;
            x=(x+t)%d;
            modify(1,now,x);
        }
    }
}