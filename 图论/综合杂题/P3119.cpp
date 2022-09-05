#include<bits/stdc++.h>
using namespace std;
#define MAXN 400005
#define INF 2147483640
bitset<MAXN>vis;
int n,m,u,v;
int dfn[MAXN],low[MAXN],belong[MAXN],head[MAXN],sum[MAXN],phead[MAXN],dis[MAXN];
int ecnt(0),nowtime(0),scccnt(0),pcnt(0);
struct mystack{
    int values[MAXN],top=0;
    bitset<MAXN>instack;
    inline void push(int x){
        instack[x]=true;
        values[top++]=x;
    }
    inline int pop(){
        instack[values[--top]]=false;
        return values[top];
    }
}s;
struct edge{
    int from,to,next;
}e[MAXN];
struct _edge{
    int to,next,w;
}points[MAXN];
inline void add(int u,int v){
    e[++ecnt]={u,v,head[u]};
    head[u]=ecnt;
}
inline void padd(int u,int v,int w){
    points[++pcnt]={v,phead[u],w};
    phead[u]=pcnt;
}
inline void tarjan(int x){
    dfn[x]=low[x]=++nowtime;
    s.push(x);
    for(register int i=head[x];i;i=e[i].next){
        int v(e[i].to);
        if(s.instack[v])low[x]=min(low[x],low[v]);
        if(!dfn[v]){
            tarjan(v);
            low[x]=min(low[x],low[v]);
        }
    }
    if(dfn[x]==low[x]){
        ++scccnt;
        int k(0);
        do{
            k=s.pop();
            ++sum[scccnt];
            belong[k]=scccnt;
        }while(k!=x);
    }
}
void spfa(int s){
    queue<int>q;
    q.push(s),dis[s]=0,vis[s]=1;
    while(!q.empty()){
        int u(q.front());
        q.pop();
        vis[u]=0;
        for(register int i=phead[u];i;i=points[i].next){
            int v(points[i].to);
            if(dis[v]<dis[u]+points[i].w){
                dis[v]=dis[u]+points[i].w;
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(register int i=1;i<=m;++i){
        cin>>u>>v;
        add(u,v);
    }
    for(register int i=1;i<=n;++i)
        if(!dfn[i])tarjan(i);
    for(register int i=1;i<=scccnt;++i)sum[scccnt+i]=sum[i];
    for(register int i=1;i<=m;++i)
        if(belong[e[i].from]!=belong[e[i].to]){
            padd(belong[e[i].from],belong[e[i].to],sum[belong[e[i].to]]);
            padd(belong[e[i].from]+scccnt,belong[e[i].to]+scccnt,sum[belong[e[i].to]+scccnt]);
            padd(belong[e[i].to],belong[e[i].from]+scccnt,sum[belong[e[i].from]+scccnt]);
        }
    spfa(belong[1]);
    cout<<dis[belong[1]+scccnt]<<endl;
}