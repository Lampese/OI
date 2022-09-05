#include<bits/stdc++.h>
using namespace std;
#define Min(a,b) a<b?a:b
#define MAXN 200005
int dfn[MAXN],low[MAXN],head[MAXN];
int ecnt(0),nowtime(0),a,b,root;
bitset<MAXN>cut;
struct edge{
	int to,next;
}e[500005];
inline void read(int &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
}
inline void add(int u,int v){
	e[++ecnt]={v,head[u]};
	head[u]=ecnt;
}
void tarjan(int x,int father){
	dfn[x]=low[x]=++nowtime;
	int child(0);
	for(register int i=head[x];i;i=e[i].next){
		int v(e[i].to);
		if(!dfn[v]){
			tarjan(v,x);
			++child;
			low[x]=Min(low[x],low[v]);
			if(((x==root&&child>1)||(x!=root&&dfn[x]<=low[v]))&&dfn[v]<=dfn[b])cut[x]=true;
		}else if(i!=(father^1))low[x]=Min(low[x],dfn[v]);
	}
}
int main(){
	int n,u,v;
	read(n);
    while(true){
        read(u),read(v);
        if(u==0&&v==0)break;
        add(u,v),add(v,u);
    }
    read(a),read(b);
	root=a;
    tarjan(a,a);
    for(register int i=1;i<=n;++i)
        if(cut[i]){
            printf("%d\n",i);
            return 0;
        }
    printf("No solution\n");
}