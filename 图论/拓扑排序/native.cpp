#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define MAXN 100000
struct edge{
    int v,next;
}e[MAXN];
int deg[MAXN],A[MAXN],head[MAXN],ecnt(0),cnt(0),n,m,u,v;
inline void add(int u,int v){
    ++deg[v];
    e[++ecnt]={v,head[u]};
    head[u]=ecnt;
}
bool toposort(){
    queue<int>q;
    for(register int i=1;i<=n;++i)if(deg[i]==0)q.push(i);
    while(!q.empty()){
        int u(q.front());q.pop();
        A[cnt++]=u;
        for(register int i=head[u];i;i=e[i].next){
            --deg[e[i].v];
            if(deg[e[i].v]==0)q.push(e[i].v);
        }
    }
    return cnt==n;
}
inline void read(int &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
}
int main(){
    read(n),read(m);
    for(register int i=1;i<=m;++i){
        read(u),read(v);
        add(u,v);
    }
    if(toposort()){
        for(register int i=0;i<cnt;++i)cout<<A[i]<<" ";
        cout<<'\n';
    }else cout<<"orz\n"<<cnt;
    return 0;
}