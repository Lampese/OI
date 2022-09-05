#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
long long head[MAXN],f[MAXN],ecnt,n,k,u,v,temp,ans;
struct egde{
    long long v,next;
}e[MAXN<<1];
inline void add(long long u,long long v){
    e[++ecnt]={v,head[u]};
    head[u]=ecnt;
}
inline void dfs(long long x,long long fa){
    for(register long long i=head[x];i;i=e[i].next){
        if(e[i].v==fa)continue;
        dfs(e[i].v,x);
        f[x]+=f[e[i].v];
    }
    for(register long long i=head[x];i;i=e[i].next){
        if(e[i].v==fa)continue;
        ans+=min(f[e[i].v],k-f[e[i].v]);
    }
}
int main(){
    cin>>n>>k;
    k<<=1;
    for(register long long i=1;i<=k;++i){
        cin>>temp;
        f[temp]=1;
    }
    for(register long long i=1;i<n;++i){
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    dfs(1,0);
    cout<<ans<<endl;
}