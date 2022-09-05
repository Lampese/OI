#include<bits/stdc++.h>
#define int long long
#define maxn 100005<<5
using namespace std;
const long long inf=0x3f3f3f3f3f3f3f3f;
int head[maxn],dis[maxn],ecnt,n,m,s;
struct edge{int v,w,next;}e[maxn];
struct _{int l,r;}tree[maxn];
inline void add(int u,int v,int w){
    e[++ecnt]={v,w,head[u]};
    head[u]=ecnt;
}
inline void build(int now,int x,int y){
    tree[now]={x,y};
    if(x==y){
        add(x+n*8,now,0),add(now+n*4,x+n*8,0);
        add(now,x+n*8,0),add(x+n*8,now+n*4,0);
        return;
    }
    add(now,now*2,0),add(now*2+n*4,now+n*4,0);
    add(now,now*2+1,0),add(now*2+1+n*4,now+n*4,0);
    int mid=(x+y)>>1;
    build(now<<1,x,mid),build(now<<1|1,mid+1,y);
}
inline void addpath(int now,int x,int y,bool type,int u,int w){
    if(tree[now].l>y||tree[now].r<x)return;
    if(x<=tree[now].l&&tree[now].r<=y){
        if(type)add(u+n*8,now,w);
        else add(now+n*4,u+n*8,w);
        return;
    }
    addpath(now<<1,x,y,type,u,w),addpath(now<<1|1,x,y,type,u,w);
}
struct node{
    int num,dis;
    bool operator <(const node &x)const{return x.dis<dis;}
};
priority_queue<node>q;
inline void dij(){
    for(register int i=1;i<=n*10;++i)dis[i]=inf;
    dis[s]=0;
    q.push({s,0});
    while(!q.empty()){
        node x=q.top();
        q.pop();
        int u=x.num;
        if(x.dis!=dis[u])continue;
        for(int i=head[u];i;i=e[i].next){
            int v=e[i].v,w=e[i].w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push({v,dis[v]});
            }
        }
    }
}
signed main(){
    int opt,u,l,r,v,w;
    cin>>n>>m>>s;
    build(1,1,n);
    while(m--){
        cin>>opt;
        if(opt==1){
            cin>>u>>v>>w;
            add(u+n*8,v+n*8,w);
        }else if(opt==2){
            cin>>u>>l>>r>>w;
            addpath(1,l,r,1,u,w);
        }else{
            cin>>u>>l>>r>>w;
            addpath(1,l,r,0,u,w);
        }
    }
    s+=8*n;
    dij();
    for(register int i=1;i<=n;++i)
        if(dis[i+n*8]!=inf)cout<<dis[i+n*8]<<" ";
        else cout<<-1<<" ";
}