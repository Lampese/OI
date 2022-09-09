#include<bits/stdc++.h>
#define MAXN 2000005
#define pushup(now) tree[now]=tree[now<<1]+tree[now<<1|1]
#define IN stdin->_IO_read_ptr<stdin->_IO_read_end?*stdin->_IO_read_ptr++:__uflow(stdin)
using namespace std;
long long arr[MAXN];
template<typename T>inline void read(T &x){
	x=0;
    int w(1);
	char ch=IN;
	while(ch<47){
        if(ch=='-')w=-1;
        ch=IN;
    }
	while(ch>47)x=(x<<1)+(x<<3)+(ch&15),ch=IN;
    if(w<0)x=-x;
}
struct node{
    long long l,r,maxx;
    node operator+(const node &x)const{
        return {l,x.r,max(maxx,x.maxx)};
    }
}tree[MAXN<<2],NP_NODE={0,0,-((long long)(1e16))};
struct tag{
    long long taga,tagb;
    tag(long long a=0,long long b=1000000002):taga(a),tagb(b){}
    bool operator==(const tag x)const{
        return x.taga==taga&&x.tagb==tagb;
    }
    tag operator+(const tag x){
        if(x.tagb!=1000000002)return x;
        else{
            this->taga+=x.taga;
            return *this;
        }
    }
}tg[MAXN<<2];
void build(long long now,long long l,long long r){
    if(l==r){
        tree[now]={l,l,arr[l]};
        return;
    }
    long long mid=(l+r)>>1;
    build(now<<1,l,mid);
    build(now<<1|1,mid+1,r);
    tg[now]=tag();
    pushup(now);
}
inline void apply(long long now,tag t){
    if(t.tagb!=1000000002)tree[now].maxx=t.tagb;
    tree[now].maxx+=t.taga;
}
inline void givetag(long long now,tag t){
    tg[now]=tg[now]+t;
    apply(now,t);
}
inline void pushdown(long long now){
    givetag(now<<1,tg[now]);
    givetag(now<<1|1,tg[now]);
    tg[now]=tag();
}
void modify(long long now,long long l,long long r,tag t){
    if(!(tg[now]==tag()))pushdown(now);
    if(tree[now].l>r||tree[now].r<l)return;
    if(tree[now].l>=l&&tree[now].r<=r){
        givetag(now,t);
        return;
    }else modify(now<<1,l,r,t),modify(now<<1|1,l,r,t);
    pushup(now);
}
node query(long long now,long long l,long long r){
    if(!(tg[now]==tag()))pushdown(now);
    if(tree[now].l>r||tree[now].r<l)return NP_NODE;
    if(tree[now].l>=l&&tree[now].r<=r)return tree[now];
    else return query(now<<1,l,r)+query(now<<1|1,l,r);
}
int main(){
    long long n,q,opt,l,r,v;
    read(n),read(q);
    for(register long long i=1;i<=n;++i)read(arr[i]);
    build(1,1,n);
    while(q--){
        read(opt);
        if(opt==1){
            read(l),read(r),read(v);
            modify(1,l,r,{0,v});
        }else if(opt==2){
            read(l),read(r),read(v);
            modify(1,l,r,{v,1000000002});
        }else{
            read(l),read(r);
            cout<<query(1,l,r).maxx<<endl;
        }
    }
}