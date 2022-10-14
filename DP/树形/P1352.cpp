#include<bits/stdc++.h>
#define MAXN 6005
using namespace std;
int n,ecnt,root,head[MAXN],point[MAXN],f[2][MAXN];
bitset<MAXN>vis,r;
struct egde{
	int v,next;
}e[MAXN<<1];
inline void add(int u,int v){
	e[++ecnt]={v,head[u]},head[u]=ecnt;
}
void dfs(int x){
	f[0][x]=0,f[1][x]=point[x];
	for(register int i=head[x];i;i=e[i].next){
		int v(e[i].v);
		dfs(v);
		f[0][x]+=max(f[0][v],f[1][v]);
		f[1][x]+=f[0][v];
	}
}
inline void read(int &x){
	x=0;
	int w(1);
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x*=w;
}
int main(){
	int u,v;
	read(n);
	for(register int i=1;i<=n;++i)read(point[i]);
	for(register int i=1;i<=n-1;++i){
		read(u),read(v);
		r[u]=1;
		add(v,u);
	}
	for(register int i=1;i<=n;++i)
		if(r[i]==0){
			root=i;
			break;
		}
	dfs(root);
	cout<<max(f[0][root],f[1][root]);
}