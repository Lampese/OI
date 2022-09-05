#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define Min(a,b) a<b?a:b
int dfn[MAXN],low[MAXN],belong[MAXN],head[MAXN],phead[MAXN],cnt[MAXN],ans[MAXN],out;
int ecnt(0),nowtime(0),scccnt(0),pcnt(0);
int vis[MAXN];
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
void tarjan(int x){
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
            ++cnt[scccnt];
            belong[k]=scccnt;
        }while(k!=x);
    }
}
void dfs(int x,int num){
    ans[x]+=cnt[x],vis[x]=num;
    for(int i=phead[x];i;i=points[i].next)
        if(vis[points[i].to]!=num)
            dfs(points[i].to,num);
}

int main(){
    int n,u,v;
    string str;
    cin>>n;
    for(register int i=1;i<=n;++i){
        cin>>str;
        for(register int j=0;j<str.size();++j)
            if(str[j]=='1')add(i,j+1);
    }
    for(register int i=1;i<=n;++i)
        if(!dfn[i])tarjan(i);
    for(register int i=1;i<=ecnt;++i)
        if(belong[e[i].from]!=belong[e[i].to])
            padd(belong[e[i].from],belong[e[i].to]);
    for(register int i=1;i<=n;++i)
        dfs(belong[i],i);
    for(register int i=1;i<=scccnt;++i)
        out+=ans[i];
    cout<<out<<endl;
}