#include<bits/stdc++.h>
using namespace std;
#define Min(a,b) a<b?a:b
#define MAXN 200005
int dfn[MAXN],low[MAXN],head[MAXN];
int ecnt(0),nowtime(0),cnt(0),root;
bitset<MAXN>cut;
struct edge{
	int to,next;
}e[MAXN];
inline void read(int &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
}
inline void add(int u,int v){
	e[++ecnt]={v,head[u]};
	head[u]=ecnt;
}
inline void sign(int x){
	if(cut[x])return;
	cut[x]=1;
	++cnt;
}
void tarjan(int x){
	dfn[x]=low[x]=++nowtime;
	int child(0);
	for(register int i=head[x];i;i=e[i].next){
		int v(e[i].to);
		if(!dfn[v]){
			tarjan(v);
			++child;
			low[x]=Min(low[x],low[v]);
			if(x==root&&child>1)sign(x);
			else if(x!=root&&dfn[x]<=low[v])sign(x);
		}else low[x]=Min(low[x],dfn[v]);
	}
}
int main(){
	int n,m,u,v;
	read(n),read(m);
	for(register int i=1;i<=m;++i){
		read(u),read(v);
		add(u,v),add(v,u);
	}
	for(register int i=1;i<=n;++i)
		if(!dfn[i]){
			root=i;
			tarjan(i);
		}
	cout<<cnt<<endl;
	for(int i=1;i<=n;++i)if(cut[i])cout<<i<<" ";
	return 0;
}