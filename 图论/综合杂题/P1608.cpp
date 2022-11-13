#include<bits/stdc++.h>
#define int long long
#define MAXN 4000005
using namespace std;
int n,m,ecnt,head[2005],dp[2005],dis[2005];
struct edge{
    int v,next,w;
}e[MAXN];
inline void add(int u,int v,int w){
    e[++ecnt]={v,head[u],w};
    head[u]=ecnt;
}
signed main(){
    cin>>n>>m;
    for(register int i=1;i<=m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
    }
    bitset<MAXN>vis;
    for(register int i=1;i<=n;++i)dis[i]=LONG_MAX;
    dp[1]=1;
    dis[1]=0;
    queue<int>q;
    q.push(1);
    while(!q.empty()){
        int u(q.front());
        q.pop();
        vis[u]=false;
        for(register int i=head[u];i;i=e[i].next){
            int v(e[i].v),w(e[i].w);
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                dp[v]=dp[u];
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }else if(dis[v]==dis[u]+w)dp[v]+=dp[u];
        }
    }
    if(dis[n]==LONG_MAX){
        cout<<"No answer"<<endl;
        return 0;
    }
    cout<<dis[n]<<" "<<dp[n]<<endl;
}