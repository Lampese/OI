#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
#define Min(a,b) a<b?a:b
const int inf=0x7fffffff;
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
    int from,to,next,w;
}e[MAXN];
struct wedge{
    int to,next,w;
}points[MAXN];
inline void add(int u,int v,int w){
    e[++ecnt]={u,v,head[u],w};
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
        if(s.instack[v])low[x]=Min(low[x],low[v]);
        if(!dfn[v]){
            tarjan(v);
            low[x]=Min(low[x],low[v]);
        }
    }   
    if(dfn[x]==low[x]){
        ++scccnt;
        int k(0);
        do{
            k=s.pop();
            belong[k]=scccnt;
        }while(k!=x);
    }
}
struct node{
    int num,val;
    node(int n,int v){num=n,val=v;}
    bool operator <(const node &x)const{return x.val<val;}
};
priority_queue<node>q;
void dij(int s){
    for(register int i=1;i<=scccnt;++i)dis[i]=inf;
    dis[s]=0;
    q.push(node(s,0));
    while(!q.empty()){
        node x=q.top();
        q.pop();
        int u(x.num);
        if(x.val!=dis[u])continue;
        for(register int i=phead[u];i;i=points[i].next){
            int v(points[i].to),w(points[i].w);
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push(node(v,dis[v]));
            }
        }
    }
}
int main(){
    int n,m,u,v,w;
    cin>>n>>m;
    for(register int i=1;i<=m;++i){
        cin>>u>>v>>w;
        add(u,v,w);
    }
    for(register int i=1;i<=n;++i)
        if(!dfn[i])tarjan(i);
    for(register int i=1;i<=m;++i)
        if(belong[e[i].from]!=belong[e[i].to])
            padd(belong[e[i].from],belong[e[i].to],e[i].w);
    dij(belong[1]);
    cout<<dis[belong[n]];
}