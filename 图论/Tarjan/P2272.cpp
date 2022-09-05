#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
#define Max(a,b) a>b?a:b
#define Min(a,b) a<b?a:b
int vis[MAXN],dfn[MAXN],low[MAXN],belong[MAXN],head[MAXN],sccsize[MAXN],phead[MAXN],f[MAXN],g[MAXN],du[MAXN],ans1,ans2,c;
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
}e[MAXN],points[MAXN];
inline void add(int u,int v){
    e[++ecnt]={u,v,head[u]};
    head[u]=ecnt;
}
inline void padd(int u,int v){
    points[++pcnt]={u,v,phead[u]};
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
            ++sccsize[scccnt];
            belong[k]=scccnt;
        }while(k!=x);
    }
}
int main(){
    int n,m,u,v;
    cin>>n>>m>>c;
    for(register int i=1;i<=m;++i){
        cin>>u>>v;
        add(u,v);
    }
    for(register int i=1;i<=n;++i)
        if(!dfn[i])tarjan(i);
    for(register int i=1;i<=m;++i)
        if(belong[e[i].from]!=belong[e[i].to])
            padd(belong[e[i].from],belong[e[i].to]);
    for(register int i=1;i<=scccnt;++i)f[i]=sccsize[i],g[i]=1;
    for(register int i=scccnt;i>=1;--i){
        for(register int j=phead[i];j;j=points[j].next){
            int v(points[j].to);
            if(vis[v]==i)continue;
            vis[v]=i;
            if(f[i]+sccsize[v]>f[v]){
                f[v]=f[i]+sccsize[v];
                g[v]=g[i];
            }else if(f[i]+sccsize[v]==f[v])g[v]=(g[v]+g[i])%c;
        }
    }
    for(register int i=1;i<=scccnt;++i){
        if(f[i]>ans1){
            ans1=f[i];
            ans2=g[i];
        }else if(f[i]==ans1)ans2=(ans2+g[i])%c;
    }
    cout<<ans1<<endl<<ans2<<endl;
}