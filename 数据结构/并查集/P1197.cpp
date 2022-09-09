#include<bits/stdc++.h>
#define MAXN 400005
using namespace std;
int head[MAXN],fa[MAXN],del[MAXN],ans[MAXN];
int n,m,k,cnt,ecnt;
bitset<MAXN>vis;
struct edge{
    int u,v,next;
}e[MAXN<<1];
inline void add(int u,int v){
    e[++ecnt]={u,v,head[u]},head[u]=ecnt;
    e[++ecnt]={u,u,head[v]},head[v]=ecnt;
}
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main(){
    cin>>n>>m;
    for(register int i=1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        add(u,v);
    }
    cin>>k;
    for(register int i=1;i<=k;++i){
        cin>>del[i];
        vis[del[i]]=true;
    }
    cnt=n-k;
    for(register int i=1;i<=n;++i)fa[i]=i;
    for(register int i=1;i<=(m<<1);++i){
        int u=e[i].u,v=e[i].v;
        if((!vis[u])&&(!vis[v])){
            int fu=find(u),fv=find(v);
            if(fu!=fv){
                --cnt;
                fa[fu]=fv;
            }
        }
    }
    ans[k+1]=cnt;
    for(register int i=k;i>=1;--i){
        ++cnt;
        int to=del[i];
        vis[to]=false;
        for(register int j=head[to];j;j=e[j].next){
            int v=e[j].v;
            int fu=find(to),fv=find(v);
            if((!vis[v])&&fu!=fv){
                fa[fu]=fv;
                --cnt;
            }
        }
        ans[i]=cnt;
    }
    for(register int i=1;i<=k+1;++i)
        cout<<ans[i]<<endl;
}