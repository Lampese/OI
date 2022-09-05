#include<bits/stdc++.h>
using namespace std;
#define Min(a,b) a<b?a:b
#define Max(a,b) a<b?b:a
#define MAXN 200005
bitset<MAXN>bridges;
int dfn[MAXN],low[MAXN],head[MAXN];
int ecnt(1),nowtime;
struct edge{
	int to,next;
}e[MAXN];
inline void add(int u,int v){
	e[++ecnt]={v,head[u]};
	head[u]=ecnt;
}
void tarjan(int x,int father){
	dfn[x]=low[x]=++nowtime;
	for(register int i=head[x];i;i=e[i].next){
		int v(e[i].to);
		if(!dfn[v]){
			tarjan(v,i);
			low[x]=Min(low[x],low[v]);
			if(low[v]>dfn[x])bridges[i]=bridges[i^1]=true;
		}else if(i!=(father^1))low[x]=Min(low[x],dfn[v]);
	}
}
inline void read(int &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
	    x=(x<<1)+(x<<3)+(ch^48);
	    ch=getchar();
	}
}
int main(){
	int n,m,u,v;
	read(n),read(m);
	for(register int i=1;i<=m;++i){
		read(u),read(v);
		add(u,v);add(v,u);
	}
	for(register int i=1;i<=n;++i)
		if(!dfn[i])tarjan(i,i);
	for(register int i=2;i<ecnt;i+=2)
	        if(bridges[i])
	            printf("%d->%d\n",Min(e[i^1].to,e[i].to),Max(e[i^1].to,e[i].to));
	return 0;
}
