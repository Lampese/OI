#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
int n,q,ecnt,head[MAXN],f[MAXN][MAXN];
struct _{
    int v,w,next;
}e[MAXN<<1];
inline void add(int u,int v,int w){
    e[++ecnt]={v,w,head[u]};
    head[u]=ecnt;
}
inline void dp(int x,int fa,int from){
    vector<int>sons;
    for(register int i=head[x];i;i=e[i].next){
        int v(e[i].v);
        if(v==fa)continue;
        dp(v,x,i);
        sons.push_back(v);
    }
    if(sons.size()){
        for(register int i=0;i<=q;++i)
            for(register int j=0;j<=i;++j)
                f[x][i]=max(f[x][i],f[sons[0]][j]+f[sons[1]][i-j]);
    }
    if(x!=1){
        for(register int i=q;i>=1;--i)
            f[x][i]=f[x][i-1]+e[from].w;
    }
}
int main(){
    cin>>n>>q;
    for(register int i=1;i<n;++i){
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    dp(1,0,0);
    cout<<f[1][q]<<endl;
}