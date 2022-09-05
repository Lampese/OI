#include<bits/stdc++.h>
using namespace std;
const int mn=500005,inf=0x7fffffff;
int m,n,s,head[mn],dis[mn],ecnt(0);
inline void read(int &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
}
struct edge{
    int v,w,next;
}e[mn];
void inline add(int u,int v,int w){
    ++ecnt;
    e[ecnt].v=v;
    e[ecnt].w=w;
    e[ecnt].next=head[u];
    head[u]=ecnt;
}
int pointer=0,W=0;
vector<int>keg[10000005];
void dij(int s){
    for(register int i=1;i<=n;++i)dis[i]=inf;
    dis[s]=0;
    keg[0].push_back(s);
    while(pointer<=W){
        int u;
        for(;pointer<=W;++pointer)
            if(keg[pointer].size()){
                u=keg[pointer].back();
                keg[pointer].pop_back();
                break;
            }
        if(pointer!=dis[u])continue;
        for(register int i=head[u];i;i=e[i].next){
            int v(e[i].v),w(e[i].w);
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                keg[dis[v]].push_back(v);
            }
        }
    }
}
int main(){
    read(m),read(n);
    int u,v,w;
    for(register int i=1;i<=n;++i){
        read(u),read(v),read(w);
        W+=w;
        add(u,v,w);
    }
    dij(1);
    printf("%d\n",dis[m]);
    return 0;
}