#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#include<cstdio>
using namespace std;
inline void read(int &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
}
void write(int x){
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
struct node{
    int val,num;
    bool operator <(const node &x)const{
        return val>x.val;
    }
};
int n,m,s,head[500005],dis[500005],ecnt(0),acount(0);
__gnu_pbds::priority_queue<node>q[215];
struct edge{
    int v,w,next;
}e[500005];
signed main(){
    int u,v,w;
    read(n),read(m),read(s);
    for(register int i=1;i<=m;++i){
        read(u),read(v),read(w);
        e[++ecnt]={v,w,head[u]};
        head[u]=ecnt;
    }
    for(register int i=1;i<=n;++i)dis[i]=2147483647;
    dis[s]=0;
    q[0].push({0,s});
    while(1){
        node x;
        for(;acount<215;++acount)
            if(!q[acount].empty()){
                x=q[acount].top();
                q[acount].pop();
                break;
            }
        if(acount==215)break;
        if(x.val!=dis[x.num])continue;
        for(register int i=head[x.num];i;i=e[i].next)
            if(dis[e[i].v]>dis[x.num]+e[i].w){
                dis[e[i].v]=dis[x.num]+e[i].w;
                q[dis[e[i].v]/10000000].push({dis[e[i].v],e[i].v});
            }
    }
    for(register int i=1;i<=n;++i){
        write(dis[i]);
        putchar(' ');
    }
}