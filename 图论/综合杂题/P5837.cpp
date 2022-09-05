#include<bits/stdc++.h>
#define MAXN 2005
#define int long long
using namespace std;
int head[MAXN],dis[MAXN],maxn=-1,ecnt,n,m,a,b,c,f;
struct egde{int v,w,f,next;}e[MAXN];
inline void add(int u,int v,int w,int f){
    e[++ecnt]={v,w,f,head[u]};
    head[u]=ecnt;
}
struct node{
    int num,dis;
    bool operator <(const node &x)const{return x.dis<dis;}
};
inline void Dij(){
    for(register int k=1;k<=1000;++k){
        for(register int i=1;i<=n;++i)dis[i]=0x7fffffff;
        priority_queue<node>q;
        dis[1]=0;
        q.push({1,0});
        while(!q.empty()){
            node x=q.top();
            q.pop();
            int u(x.num);
            if(x.dis!=dis[u])continue;
            for(int i=head[u];i;i=e[i].next){
               int v=e[i].v,w=e[i].w;
                if(dis[v]>dis[u]+w&&e[i].f>=k){
                    dis[v]=dis[u]+w;
                    q.push({v,dis[v]});
                }
            }
        }
        if(dis[n]!=0x7fffffff)maxn=max(maxn,k*1000000/dis[n]);
    }
}
signed main(){
    cin>>n>>m;
    for(register int i=1;i<=m;++i){
        cin>>a>>b>>c>>f;
        add(a,b,c,f);
        add(b,a,c,f);
    }
    Dij();
    cout<<maxn<<endl;
}