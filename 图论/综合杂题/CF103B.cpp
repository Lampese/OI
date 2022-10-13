#include<bits/stdc++.h>
#define MAXN 5005
using namespace std;
int cnt,ecnt,head[MAXN];
bitset<MAXN>vis;
struct edge{
    int v,next;
}e[MAXN<<1];
inline void add(int u,int v){
    e[++ecnt]={v,head[u]};
    head[u]=ecnt;
}
void dfs(int x){
    vis[x]=1;
    ++cnt;
    for(register int i=head[x];i;i=e[i].next)
        if(!vis[e[i].v])
            dfs(e[i].v);
}
int main(){
    int n,m;
    cin>>n>>m;
    for(register int i=1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    if(m!=n)cout<<"NO"<<endl;
    else{
        dfs(1);
        if(cnt!=n)cout<<"NO"<<endl;
        else cout<<"FHTAGN!"<<endl;
    }
}