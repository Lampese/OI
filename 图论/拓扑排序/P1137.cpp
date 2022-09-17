#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,m,ecnt,f[MAXN],deg[MAXN],head[MAXN];
struct egde{
    int v,next;
}e[MAXN<<1];
inline void add(int u,int v){
    ++deg[v];
    e[++ecnt]={v,head[u]};
    head[u]=ecnt;
}
int main(){
    cin>>n>>m;
    for(register int i=1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        add(u,v);
    }
    queue<int>q;
    for(register int i=1;i<=n;++i)  
        if(deg[i]==0)q.push(i);
    while(!q.empty()){
        int u(q.front());
        q.pop();
        for(register int i=head[u];i;i=e[i].next){
            int v(e[i].v);
            f[v]=max(f[v],f[u]+1);
            if(--deg[v]==0)q.push(v);
        }
    }
    for(register int i=1;i<=n;++i)cout<<f[i]+1<<endl;
}