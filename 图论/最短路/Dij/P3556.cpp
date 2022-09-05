#include<bits/stdc++.h>
using namespace std;
const int MAXN=5005<<1,inf=0x7fffffff;
int n,m,k,ecnt,head[MAXN],dis[MAXN][MAXN];
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
}e[MAXN];
void inline add(int u,int v,int w){
    e[++ecnt]={v,w,head[u]};
    head[u]=ecnt;
}
void dij(int s){
    int pointer=0;
    vector<int>bukket[5005<<1];
    for(register int i=1;i<=n;++i)dis[s][i]=inf;
    dis[s][s]=0;
    bukket[0].push_back(s);
    while(pointer<=m){
        int u;
        for(;pointer<=m;++pointer)
            if(bukket[pointer].size()){
                u=bukket[pointer].back();
                bukket[pointer].pop_back();
                break;
            }
        if(pointer!=dis[s][u])continue;
        for(register int i=head[u];i;i=e[i].next){
            int v(e[i].v),w(e[i].w);
            if(dis[s][v]>dis[s][u]+w){
                dis[s][v]=dis[s][u]+w;
                bukket[dis[s][v]].push_back(v);
            }
        }
    }
}
int main(){
    int u,v,d;
    read(n),read(m),read(k);
    for(register int i=1;i<=m;++i){
        read(u),read(v);
        add(u,v,1);
        add(v,u,1);
    }
    m<<=1;
    for(register int i=1;i<=n;++i)dij(i);
    for(register int i=1;i<=k;++i){
        read(u),read(v),read(d);
        if(dis[u][v]==inf)cout<<"NIE"<<endl;
        else if(dis[u][v]==d)cout<<"TAK"<<endl;
        else if(dis[u][v]&1)cout<<"NIE"<<endl;
        else cout<<"TAK"<<endl;
    }
}