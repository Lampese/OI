#include<bits/stdc++.h>
using namespace std;
bitset<5000005>vis;
int n,m,p,ecnt,head[5000005],dis[5000005];
struct node{int l,r;}tree[5000005];
struct edge{int v,w,next;}e[5000005<<1];
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
        if(type)add(u,now,w);
        else add(now+n*4,u,w);
        return;
    }
    addpath(now<<1,x,y,type,u,w),addpath(now<<1|1,x,y,type,u,w);
}
inline void bfs(){
    memset(dis,0x3f3f3f3f,sizeof(dis));
    deque<int>q;
    dis[p]=0;
    q.push_front(p);
    while(!q.empty()){
        int u(q.front());
        q.pop_front();
        if(vis[u])continue;
        vis[u]=true;
        for(register int i=head[u];i;i=e[i].next){
            int v(e[i].v),w(e[i].w);
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(w==1)q.push_back(v);
                else q.push_front(v);
            }
        }
    }
}
int main(){
    int a,b,c,d;
    cin>>n>>m>>p;
    int cnt=n*9;
    build(1,1,n);   
    for(register int i=1;i<=m;++i){
        cin>>a>>b>>c>>d;
        ++cnt;
        addpath(1,a,b,1,cnt,1),addpath(1,c,d,0,cnt,1);
        ++cnt;
        addpath(1,c,d,1,cnt,1),addpath(1,a,b,0,cnt,1);
    }
    p+=n*8;
    bfs();
    for(register int i=1;i<=n;++i)cout<<dis[i+n*8]/2<<endl;
}