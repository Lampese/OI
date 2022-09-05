#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005,inf=0x7fffffff;
int n,m,s,ecnt,head[MAXN],dis[MAXN];
inline void read(int &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
}
struct node{
    int num,dis;
    bool operator <(const node &x)const{return x.dis<dis;}
};
struct edge{
    int v,w,next;
}e[MAXN];
inline void add(int u,int v,int w){
    e[++ecnt]={v,w,head[u]};
    head[u]=ecnt;
}
priority_queue<node>q;
inline void dij(){
    for(int i=1;i<=n;++i)dis[i]=inf;
    dis[s]=0;
    q.push({s,0});
    while(!q.empty()){
        node x=q.top();
        q.pop();
        int u=x.num;
        if(x.dis!=dis[u])continue;
        for(int i=head[u];i;i=e[i].next){
            int v=e[i].v,w=e[i].w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push({v,dis[v]});
            }
        }
    }
}
int main(){
    read(n),read(m),read(s);
    int u,v,w;
    for(int i=1;i<=m;++i){
        read(u),read(v),read(w);
        add(u,v,w);
    }
    dij();
    for(int i=1;i<=n;++i)printf("%d ",dis[i]);
    return 0;
}