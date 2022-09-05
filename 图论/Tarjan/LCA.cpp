#include<bits/stdc++.h>
using namespace std;
#define MAXN 500005
int head[MAXN],headq[MAXN],fa[MAXN],lca[MAXN];
int n,m,s,a,b,ecnt,qcnt;
bitset<MAXN>vis;
struct edge{
	int to,next;
}e[MAXN<<1];
struct ask{
	int id,to,next;
}que[MAXN<<1];
inline void add(int u,int v){
    e[++ecnt]={v,head[u]},head[u]=ecnt;
    e[++ecnt]={u,head[v]},head[v]=ecnt;
}
inline void add_q(int u,int v,int i){
    que[++qcnt]={i,v,headq[u]},headq[u]=qcnt;
    que[++qcnt]={i,u,headq[v]},headq[v]=qcnt;
}
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void tarjan(int u){
	vis[u]=1;
	for(int i=head[u];i;i=e[i].next){
		int v(e[i].to);
		if(!vis[v]){
			tarjan(v);
			fa[v]=find(u);
		}
	}
	for(int i=headq[u];i;i=que[i].next){
		int v(que[i].to);
		if(vis[v])lca[que[i].id]=find(v);
	}
}
void print(int x){
    if(x>9)print(x/10);
    putchar(x%10+'0');
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
	read(n),read(m),read(s);
	for(int i=1;i<n;++i){
		read(a),read(b);
		add(a,b);
	}
	for(int i=1;i<=m;++i){
		read(a),read(b);
		add_q(a,b,i);
	}
	for(int i=1;i<=n;++i)fa[i]=i;
	tarjan(s);
	for(int i=1;i<=m;++i){
        print(lca[i]);
        putchar('\n');
    }
}