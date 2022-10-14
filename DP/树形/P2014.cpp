#include<bits/stdc++.h>
#define MAXN 305
using namespace std;
int n,m,ecnt,value[MAXN],head[MAXN],dp[MAXN][MAXN];
struct edge{
    int v,next;
}e[MAXN<<1];
inline void add(int u,int v){
    e[++ecnt]={v,head[u]};
    head[u]=ecnt;
}
inline void f(int x){
    for(register int i=head[x];i;i=e[i].next){
        int to=e[i].v;
        f(to);
        for(register int t=m;t>=0;--t)
            for(register int j=0;j<=t;++j)
                dp[x][t]=max(dp[x][t],dp[x][t-j]+dp[to][j]);
    }
    if(x!=0){
        for(register int t=m;t>=1;--t)
            dp[x][t]=dp[x][t-1]+value[x];
    }
}
int main(){
    cin>>n>>m;
    for(register int i=1;i<=n;++i){
        int k;
        cin>>k>>value[i];
        add(k,i);
    }
    f(0);
    cout<<dp[0][m]<<endl;
}