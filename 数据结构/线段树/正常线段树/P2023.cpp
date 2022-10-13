#include<bits/stdc++.h>
using namespace std;
const int N=100005;
long long p;
#define pushup(now) tree[now]=tree[now<<1]+tree[now<<1|1];
struct Tag {
	long long mul,add;
	Tag(long long mul=1,long long add=0):mul(mul),add(add){}
	Tag operator +(const Tag &x)const {
		return {(mul*x.mul)%p,(x.mul*add+x.add)%p};
	}
}; 
struct node {
	long long l,r,sum,len;
	Tag tag;
	node operator +(const node &x)const {
		return {l,x.r,(sum+x.sum)%p,len+x.len,Tag()};
	}
} tree[N<<2];
long long arr[N];
void build(long long now,long long x,long long y) {
	if(x==y) {
		tree[now]={x,y,arr[x],1,Tag()};
		return;
	}
	long long mid=(x+y)>>1;
	build(now<<1,x,mid);
	build(now<<1|1,mid+1,y);
	pushup(now);
}
void apply(long long now,Tag tag) {
	tree[now].sum*=tag.mul;
	tree[now].sum%=p;
	tree[now].sum+=(tag.add*tree[now].len)%p;
	tree[now].sum%=p;
}
void givetag(long long now,Tag tag) {
	tree[now].tag=tree[now].tag+tag;
	apply(now,tag);
}
inline void pushdown(long long now) {
	givetag(now<<1,tree[now].tag);
	givetag(now<<1|1,tree[now].tag);
	tree[now].tag=Tag();
}
node query(long long now,long long x,long long y) {
	if(tree[now].l!=tree[now].r) {
		pushdown(now);
	}
	if(x<=tree[now].l&&tree[now].r<=y)
		return tree[now];
	long long mid=(tree[now].l+tree[now].r)>>1;
	if(x<=mid&&y>mid)
		return query(now<<1,x,y)+query(now<<1|1,x,y);
	if(x<=mid)
		return query(now<<1,x,y);
	if(y>mid)
		return query(now<<1|1,x,y);
}
void modify(long long now,long long x,long long y,Tag tag) {
	if(tree[now].l!=tree[now].r)
		pushdown(now);
	if(x<=tree[now].l&&tree[now].r<=y) {
		givetag(now,tag);
		return ;
	}
	long long mid=(tree[now].l+tree[now].r)>>1;
	if(x<=mid)
		modify(now<<1,x,y,tag);
	if(y>mid)
		modify(now<<1|1,x,y,tag);
	pushup(now);
}
long long n,m;
int main() {
	cin>>n>>p;
	for(long long i=1;i<=n;++i){
		cin>>arr[i];
	}
	build(1,1,n);
    cin>>m;
	for(long long i=1;i<=m;++i){
		long long opt,x,y,k;
		cin>>opt;
		if(opt==1){
			cin>>x>>y>>k;
			modify(1,x,y,{k,0});
		}
		if(opt==2){
			cin>>x>>y>>k;
			modify(1,x,y,{1,k});
		}
		if(opt==3){
			cin>>x>>y;
			cout<<query(1,x,y).sum%p<<endl;
		}
	}
}