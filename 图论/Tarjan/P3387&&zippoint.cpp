#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define Max(a,b) a>b?a:b
#define Min(a,b) a<b?a:b
int dfn[MAXN],low[MAXN],belong[MAXN],head[MAXN],p[MAXN],sum[MAXN],phead[MAXN],f[MAXN],ans=0;
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
            sum[scccnt]+=p[k];
            belong[k]=scccnt;
        }while(k!=x);
    }
}
void search(int x){
    if(f[x])return;
    f[x]=sum[x];
    int maxsum=0;
    for(register int i=phead[x];i;i=points[i].next){
        if(!f[points[i].to])search(points[i].to);
        maxsum=Max(maxsum,f[points[i].to]);
    }
    f[x]+=maxsum;
}
int main(){
    int n,m,u,v;
    cin>>n>>m;
    for(register int i=1;i<=n;++i)cin>>p[i];
    for(register int i=1;i<=m;++i){
        cin>>u>>v;
        add(u,v);
    }
    for(register int i=1;i<=n;++i)
        if(!dfn[i])tarjan(i);
    for(register int i=1;i<=m;++i)
        if(belong[e[i].from]!=belong[e[i].to])
            padd(belong[e[i].from],belong[e[i].to]);
    for(register int i=1;i<=scccnt;++i){
        if(!f[i])search(i);
        ans=Max(ans,f[i]);
    }
    cout<<ans<<endl;
    return 0;
}