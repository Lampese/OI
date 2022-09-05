#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
bitset<MAXN>vis;
int fa[MAXN],tick[MAXN],nextfa[MAXN],cnt(1);
inline void read(int &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
}
int find(int u){
	if(vis[u])return u;
	if(tick[u]==cnt)return nextfa[u];
	tick[u]=cnt;
	return nextfa[u]=find(fa[u]);
}
int main(){
	vis[1]=fa[1]=1;
	int n,q,u,v;
	char opt;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)tick[i]=nextfa[i]=1;
	for(int i=1;i<n;++i){
		read(u),read(v);
		fa[v]=u;
	}
	for(int i=0;i<q;++i){
		char opt=getchar_unlocked();
		while(opt<'A'||opt>'Z')opt=getchar_unlocked();
		read(u);
		if(opt=='C')(!vis[u])?vis[u]=1,++cnt:0;
		else printf("%d\n",find(u));
	}
}