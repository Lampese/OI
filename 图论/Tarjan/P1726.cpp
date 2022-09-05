 
#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define Max(a,b) a>b?a:b
#define Min(a,b) a<b?a:b
int dfn[MAXN],low[MAXN],head[MAXN];
int ecnt(0),nowtime(0),scccnt(0);
vector<int>ans;
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
inline void add(int u,int v){
    e[++ecnt]={u,v,head[u]};
    head[u]=ecnt;
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
        vector<int>scc;
        do{
            k=s.pop();
            scc.push_back(k);
        }while(k!=x);
        sort(scc.begin(),scc.end());
        if(scc.size()>ans.size())ans=scc;
        else if(scc.size()==ans.size()&&scc[0]<ans[0])ans=scc;
    }
}
int main(){
    int n,m,u,v,t;
    cin>>n>>m;
    for(register int i=1;i<=m;++i){
        cin>>u>>v>>t;
        if(t==1)add(u,v);
        else add(u,v),add(v,u);
    }
    for(register int i=1;i<=n;++i)
        if(!dfn[i])tarjan(i);
    cout<<ans.size()<<endl;
    for(int i:ans)
        cout<<i<<' ';
}