#include<bits/stdc++.h>
#define MAXN 1000005
using namespace std;
long long n,m,ecnt,nowtime,root,ans[MAXN],_size[MAXN],head[MAXN],dfn[MAXN],low[MAXN];
struct edge{
    int v,next;
}e[MAXN];
bitset<MAXN>cut;
void add(long long u,long long v){
	e[++ecnt]={v,head[u]};
    head[u]=ecnt;
}
void tarjan(long long x){
	dfn[x]=low[x]=++nowtime;
	long long flag(0),sum(0);
	_size[x]=1;
	for(int i=head[x];i;i=e[i].next){
		long long y=e[i].v;
		if(!dfn[y]){
			tarjan(y);
			_size[x]+=_size[y];
			low[x]=min(low[x],low[y]);
			if(low[y]>=dfn[x]){
				++flag;
				ans[x]+=_size[y]*(n-_size[y]);
				sum+=_size[y];
				if(x!=root||flag>1)cut[x]=true;
			}
		}
		else low[x]=min(low[x],dfn[y]);
	}
	if(cut[x])ans[x]+=(n-sum-1)*(sum+1)+(n-1);
	else ans[x]=(n-1)<<1;
}
int main(){
	scanf("%lld%lld",&n,&m);
    long long x,y;
	for(int i=1;i<=m;++i){
		scanf("%lld%lld",&x,&y);
		if(x==y)continue;
		add(x,y),add(y,x);
	}
	tarjan(1);
	for(int i=1;i<=n;++i)printf("%lld\n",ans[i]);
} 
