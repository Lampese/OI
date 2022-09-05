#include<bits/stdc++.h>
#define MAXN 10005
#define MAXM 200005
using namespace std;
bitset<MAXN>vis,vvis,vvvis;
int n,m,s,t,u,v,ecnt,rcnt,head[MAXN],rhead[MAXN],dis[MAXN];
struct egde{
    int v,next;
}e[MAXM],r[MAXM];
inline void add(int u,int v){
    e[++ecnt]={v,head[u]};
    head[u]=ecnt;
    r[ecnt]={u,rhead[v]};
    rhead[v]=ecnt;
}
void bfs1(){
    queue<int>q;
    q.push(t);
    vis[t]=true;
    while(!q.empty()){
        int u(q.front());
        q.pop();
        for(register int i=rhead[u];i;i=r[i].next){
            int v(r[i].v);
            if(vis[v])continue;
            q.push(v);
            vis[v]=true;
        }
    }
}
void bfs2(){
    for(register int i=1;i<=n;++i)dis[i]=400000;
    queue<int>q;
    q.push(s);
    dis[s]=0;
    vvis[s]=true;
    while(!q.empty()){
        int u(q.front());
        q.pop();
        for(register int i=head[u];i;i=e[i].next){
            int v(e[i].v);
            if(vvvis[v])continue;  
            if(vvis[v])continue;  
            vvis[v]=true;
            q.push(v);
            if(dis[v]>dis[u]+1)
                dis[v]=dis[u]+1;
        }
    }
}
int main(){
    cin>>n>>m;
    for(register int i=1;i<=m;++i){
        cin>>u>>v;
        if(u!=v)add(u,v);
    }
    cin>>s>>t;
    bfs1();
    for(register int i=1;i<=n;++i)
        if(!vis[i])
            for(register int j=rhead[i];j;j=r[j].next){
                int v(r[j].v);
                if(vis[v])vvvis[v]=true;
            }
    bfs2();
    cout<<(dis[t]==400000?-1:dis[t])<<endl;
}