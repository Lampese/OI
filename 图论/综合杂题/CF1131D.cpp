#include<bits/stdc++.h>
#define MAXN 4000005
using namespace std;
int dfn[MAXN],low[MAXN],belong[MAXN],head[MAXN],phead[MAXN],du[MAXN],f[MAXN];
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
int n,m,ecnt,pcnt,scccnt,nowtime;
char temp;
struct edge{
    int from,to,next,w;
}e[MAXN],points[MAXN];
inline void add(int u,int v,int w){
    e[++ecnt]={u,v,head[u],w};
    head[u]=ecnt;
}
inline void padd(int u,int v){
    ++du[v];
    points[++pcnt]={u,v,phead[u]};
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
            belong[k]=scccnt;
        }while(k!=x);
    }
}
void toposort(){
    queue<int>q;
    for(register int i=1;i<=scccnt;++i)
        if(du[i]==0){
            q.push(i);
            f[i]=1;
        }
    while(!q.empty()){
        int u(q.front());
        q.pop();
        for(register int i=phead[u];i;i=points[i].next){
            int v(points[i].to);
            f[v]=max(f[v],f[u]+1);
            if(--du[v]==0)q.push(v);
        }
    }
}
int main(){
    cin>>n>>m;
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=m;++j){
            cin>>temp;
            if(temp=='=')add(i,n+j,0),add(n+j,i,0);
            else if(temp=='>')add(n+j,i,1);
            else add(i,n+j,1);
        }
    for(register int i=1;i<=n+m;++i)
        if(!dfn[i])tarjan(i);
    for(register int i=1;i<=ecnt;++i)
        if(belong[e[i].from]!=belong[e[i].to])
            padd(belong[e[i].from],belong[e[i].to]);
        else if(e[i].w){
            cout<<"No"<<endl;
            return 0;
        }
    toposort();
    cout<<"Yes"<<endl;
    for(register int i=1;i<=n;++i)cout<<f[belong[i]]<<" ";
    cout<<endl;
    for(register int j=1;j<=m;++j)cout<<f[belong[n+j]]<<" ";
}