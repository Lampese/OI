#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int head[MAXN],du[MAXN],s[MAXN],ecnt;
struct edge{
    int v,w,next;
}e[MAXN];
inline void add(int u,int v,int w){
    e[++ecnt]={v,w,head[u]};
    head[u]=ecnt;
}
int main(){
    int n,m,c,u,v,w;
    cin>>n>>m>>c;
    for(register int i=1;i<=n;++i)cin>>s[i];
    for(register int i=1;i<=c;++i){
        cin>>u>>v>>w;
        add(u,v,w);
        ++du[v];
    }
    queue<int >q;
    for(register int i=1;i<=n;++i)
        if(du[i]==0)
            q.push(i);
    while(!q.empty()){
        int u(q.front());
        q.pop();
        for(register int i=head[u];i;i=e[i].next){
            int v(e[i].v);
            s[v]=max(s[v],s[u]+e[i].w);
            if(--du[v]==0)q.push(v);
        }
    }
    for(register int i=1;i<=n;++i)
        cout<<s[i]<<endl;
}