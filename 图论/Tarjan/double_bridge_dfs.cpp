#include<bits/stdc++.h>
using namespace std;
#define Min(a,b) a<b?a:b
#define MAXN 1000005
int dfn[MAXN],low[MAXN],head[MAXN],belong[MAXN];
int ecnt(1),nowtime,dcccnt;
bitset<MAXN>vis,bridges;
struct edge{
	int to,next;
}e[MAXN<<1];
inline void add(int u,int v){
	e[++ecnt]={v,head[u]},head[u]=ecnt;
    e[++ecnt]={u,head[v]},head[v]=ecnt;
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
void dfs(int x){
    vis[x]=1;
    for(register int i=head[x];i;i=e[i].next){
        if(bridges[i])continue;
        int v(e[i].to);
        if(!vis[v])dfs(v);
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
		add(u,v);
	}
	for(register int i=1;i<=n;++i)
		if(!dfn[i])tarjan(i,i);
    for(register int i=1;i<=n;++i)
        if(!vis[i]){
            dfs(i);
            ++dcccnt;
        }
    cout<<dcccnt<<endl;
    
}