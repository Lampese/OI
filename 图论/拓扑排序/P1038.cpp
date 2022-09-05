#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct edge{
    int to,next,w;
}e[10005];
int deg[105],head[10005],U[105],C[105],n,p,out[105],ecnt(0);
inline void add(int u,int v,int w){
    ++deg[v],++out[u],++ecnt;
    e[ecnt].to=v;
    e[ecnt].w=w;
    e[ecnt].next=head[u];
    head[u]=ecnt;
}
inline void toposort(){
    queue<int>q;
    for(register int i=1;i<=n;++i)if(deg[i]==0)q.push(i);
    while(!q.empty()){
        int u(q.front());q.pop();
        for(register int i=head[u];i;i=e[i].next){
            --deg[e[i].to];
            if(C[u]>0)C[e[i].to]+=C[u]*e[i].w;
            if(deg[e[i].to]==0)q.push(e[i].to);
        }
    }
}
inline void read(int &x){
	x=0;
    int w(1);
	char ch=getchar();
	while(ch<'0'||ch>'9'){
        if(ch=='-')w=-1;
        ch=getchar();
    }
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
    x*=w;
}
int main(){
    read(n),read(p);
    for(register int i=1;i<=n;++i){
        read(C[i]),read(U[i]);
        if(C[i]==0)C[i]-=U[i];
    }
    int u,v,w,output,flag=1;
    for(register int i=1;i<=p;++i){
        read(u),read(v),read(w);
        add(u,v,w);
    }
    toposort();
    for(register int i=1;i<=n;++i)
        if(C[i]>0&&out[i]==0){
            cout<<i<<" "<<C[i]<<endl;
            flag=0;
        }
    if(flag==1)cout<<"NULL"<<endl;
    return 0;
}