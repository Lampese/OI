#include<bits/stdc++.h>
#define MAXN 2000005
using namespace std;
const int P=100003;
bitset<MAXN>vis;
int n,m,ecnt,head[MAXN],dis[MAXN],dp[MAXN];
struct edge{
    int v,next;
}e[MAXN<<1];
inline void add(int u,int v){
    e[++ecnt]={v,head[u]};
    head[u]=ecnt;
}
int main(){
    cin>>n>>m;
    for(register int i=1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        add(u,v),add(v,u);
    }
    memset(dis,0x3f,sizeof dis);
    dp[1]=1;
    dis[1]=0;
    queue<int>q;
    q.push(1);
    while(!q.empty()){
        int u(q.front());
        q.pop();
        vis[u]=false;
        for(register int i=head[u];i;i=e[i].next){
            int v(e[i].v);
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                dp[v]=dp[u];
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }else if(dis[v]==dis[u]+1){
                dp[v]+=dp[u];
                dp[v]%=P;
            }
        }
    }
    for(register int i=1;i<=n;++i)
        cout<<dp[i]<<endl;
}