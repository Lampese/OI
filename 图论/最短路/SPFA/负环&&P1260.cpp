#include<bits/stdc++.h>
using namespace std;
#define MAXN 500005
#define INF 2147483647;
bitset<MAXN>vis;
int head[MAXN],dis[MAXN],cnt[MAXN],m,n,ecnt;
struct edge{
    int to,next,w;
}e[MAXN];
inline void add(int u,int v,int w){
    e[++ecnt]={v,head[u],w},head[u]=ecnt;
}
void spfa(int s){
    for(register int i=1;i<=n;++i)dis[i]=INF;
    queue<int>q;
    q.push(s),dis[s]=0,vis[s]=1;
    while(!q.empty()){
        int u(q.front());
        q.pop();
		if(++cnt[u]>n-1){
			puts("NO SOLUTION");
			return;
		}
        vis[u]=0;
        for(register int i=head[u];i;i=e[i].next){
            int v(e[i].to);
            if(dis[v]>dis[u]+e[i].w){
                dis[v]=dis[u]+e[i].w;
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    int minn;
    for(register int i=1;i<=n;++i)minn=min(minn,dis[i]);
    for(register int i=1;i<=n;++i)cout<<dis[i]-minn<<endl;
}
int main(){
    int u,v,w=INF;
    cin>>n>>m;
    for(register int i=1;i<=m;++i){
        cin>>u>>v>>w;
        add(v,u,w);
    }
    for(register int i=1;i<=n;++i)add(n+1,i,0);
    spfa(n+1);
}