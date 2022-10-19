#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
const long long m=1000000007;
long long ecnt,kcnt,head[MAXN],vis[MAXN],f[MAXN][4];
struct egde{
    long long v,next;
}e[MAXN<<1];
inline void add(long long u,long long v){
    e[++ecnt]={v,head[u]};
    head[u]=ecnt;
}
inline void dp(long long x,long long fa){
    for(register long long i=1;i<=3;++i){
        if(vis[x]!=0){
            if(vis[x]==i)f[x][i]=1;
            else f[x][i]=0;
        }
        else f[x][i]=1;
    }
    for(register long long i=head[x];i;i=e[i].next){
        long long v(e[i].v);
        if(v!=fa){
            dp(v,x);
            f[x][1]=f[x][1]*(f[v][2]+f[v][3])%m;
            f[x][2]=f[x][2]*(f[v][1]+f[v][3])%m;
            f[x][3]=f[x][3]*(f[v][1]+f[v][2])%m;
        }
    }
}
int main(){
    long long n,k,u,v,temp,color;
    cin>>n>>k;
    for(register long long i=1;i<n;++i){
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    for(register long long i=1;i<=k;++i){
        cin>>temp>>color;
        vis[temp]=color;
    }
    dp(1,0);
    cout<<(f[1][1]+f[1][2]+f[1][3])%m<<endl;
}