#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
const long long p=10007;
long long n,maxx=-1,sum,ecnt,head[MAXN],W[MAXN],f[MAXN];
struct edge{
    long long v,next;
}e[MAXN<<1];
inline void add(long long u,long long v){
    e[++ecnt]={v,head[u]};
    head[u]=ecnt;
}
void dfs(long long u,long long fa,long long dep){
    if(dep)f[u]=fa;
    if(dep>=3){
        maxx=max(maxx,W[u]*W[f[fa]]);
        sum+=W[u]*W[f[fa]]*2;
        sum%=p;
    }
    if(!head[u])return;
    long long heremax1=-1,heremax2=-1,heremaxre=0,Sum=0;
    for(register long long i=head[u];i;i=e[i].next){
        if(e[i].v==fa)continue;
        Sum+=(W[e[i].v]);
        heremax1=max(heremax1,W[e[i].v]);
    }
    for(register long long i=head[u];i;i=e[i].next){
        if(e[i].v==fa)continue;
        if(W[e[i].v]==heremax1)
            ++heremaxre;
    }
    if(heremaxre>1)maxx=max(maxx,heremax1*heremax1);
    for(register long long i=head[u];i;i=e[i].next){
        if(e[i].v==fa)continue;
        sum+=W[e[i].v]*(Sum-W[e[i].v]);
        sum%=p;
        if(W[e[i].v]!=heremax1)heremax2=max(heremax2,W[e[i].v]);
    }
    maxx=max(maxx,heremax1*heremax2);
    for(register long long i=head[u];i;i=e[i].next)
        if(e[i].v!=fa)
            dfs(e[i].v,u,dep+1);
}
signed main(){
    long long u,v;
    cin>>n;
    for(register long long i=1;i<n;++i){
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    for(register long long i=1;i<=n;++i)cin>>W[i];
    dfs(1,0,1);
    cout<<maxx<<" "<<sum%p<<endl;
}