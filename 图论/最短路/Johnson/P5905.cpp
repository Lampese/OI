#include<bits/stdc++.h>
#define int long long
#define MAXN 6005
using namespace std;
int n,m,ecnt,ncnt,head[MAXN],cnt[MAXN],h[MAXN],nhead[MAXN],dis[MAXN];
struct edge{
    int v,next,w;
}e[MAXN<<1],newG[MAXN<<1];
inline void add(int u,int v,int w){
    e[++ecnt]={v,head[u],w};
    head[u]=ecnt;
}
inline void nadd(int u,int v,int w){
    newG[++ncnt]={v,nhead[u],w};
    nhead[u]=ncnt;
}
inline bool spfa(int s){
    memset(h,0x3f,sizeof h);
    h[s]=0;
    bitset<MAXN>vis;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int u(q.front());
        q.pop();
        vis[u]=false;
        if(++cnt[u]>=n+1)return false;
        for(register int i=head[u];i;i=e[i].next){
            int v(e[i].v);
            if(h[v]>h[u]+e[i].w){
                h[v]=h[u]+e[i].w;
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    }
    return true;
}
struct node{
    int num,val;
    bool operator <(const node &x)const{
        return x.val<val;
    }
};
inline void dij(int s){
    dis[s]=0;
    priority_queue<node>q;
    q.push({s,0});
    while(!q.empty()){
        auto x(q.top());
        int u(x.num);
        q.pop();
        if(dis[u]!=x.val)continue;
        for(register int i=nhead[u];i;i=newG[i].next){
            int v(newG[i].v);
            if(dis[v]>dis[u]+newG[i].w){
                dis[v]=dis[u]+newG[i].w;
                q.push({v,dis[v]});
            }
        }
    }
}
signed main(){
    cin>>n>>m;
    for(register int i=1;i<=m;++i){
        int u,v,w;  
        cin>>u>>v>>w;
        add(u,v,w);
    }
    for(register int i=1;i<=n;++i)add(n+1,i,0);
    if(!spfa(n+1)){
        cout<<-1<<endl;
        return 0;
    }
    for(register int i=1;i<=n;++i)
        for(register int j=head[i];j;j=e[j].next){
            int v(e[j].v),w(e[j].w);
            nadd(i,v,w+h[i]-h[v]);
        }
    for(register int i=1;i<=n;++i){
        for(register int i=1;i<=n;++i)dis[i]=1000000000;
        long long ans=0;
        dij(i);
        for(register int j=1;j<=n;++j){
            if(dis[j]==1000000000)ans+=j*dis[j];
            else ans+=(long long)j*(long long)(dis[j]+h[j]-h[i]);
        }
        cout<<ans<<endl;
    }
}