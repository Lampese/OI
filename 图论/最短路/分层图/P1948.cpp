#include<bits/stdc++.h>
using namespace std;
#define MAXN 50005
int head[6000060],dis[6000060],ecnt,n,m,k;
struct edge{
    int to,next,w;
}e[6000060];
inline void add(int u,int v,int w){
    e[++ecnt]={v,head[u],w},head[u]=ecnt;
}
inline void read(int &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
}
struct node{
    int num,val;
    node(int n,int v){num=n,val=v;}
    bool operator <(const node &x)const{return x.val<val;}
};
priority_queue<node>q;
void dij(int s){
    memset(dis,0x3f3f3f3f,sizeof(dis));
    dis[s]=0;
    q.push(node(s,0));
    while(!q.empty()){
        node x=q.top();
        q.pop();
        int u(x.num);
        if(x.val!=dis[u])continue;
        for(register int i=head[u];i;i=e[i].next){
            int v(e[i].to),w(e[i].w);
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push(node(v,dis[v]));
            }
        }
    }
}
int main(){
    int u,v,w,s,t;
    read(n),read(m),read(k),read(s),read(t);
    for(register int i=1;i<=m;++i){
        read(u),read(v),read(w);
        add(u,v,w),add(v,u,w);
        for(register int j=1;j<=k;++j){
            add(u+(j-1)*n,v+j*n,0);
            add(v+(j-1)*n,u+j*n,0);
            add(u+j*n,v+j*n,w);
            add(v+j*n,u+j*n,w);
        }
    }
    dij(s);
    int ans=0x3f3f3f3f;
    for(register int i=0;i<=k;++i)
        ans=min(ans,dis[t+i*n]);
    cout<<ans<<endl;
}