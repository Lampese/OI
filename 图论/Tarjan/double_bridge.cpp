//边双的充要条件：边双连通分量中任意一条边都包含在至少一个简单环中
#include<bits/stdc++.h>
using namespace std;
#define Min(a,b) a<b?a:b
#define MAXN 2000005
int dfn[MAXN],low[MAXN],head[MAXN],belong[MAXN];
vector<int>out[10005];
int ecnt(1),nowtime,dcccnt;
struct edge{
	int to,next;
}e[MAXN<<1];
inline void add(int u,int v){
	e[++ecnt]={v,head[u]},head[u]=ecnt;
    e[++ecnt]={u,head[v]},head[v]=ecnt;
}
struct mystack{
    int values[MAXN],top=0;
    inline void push(int x){
        values[top++]=x;
    }
    inline int pop(){
        return values[--top];
    }
}s;
void tarjan(int x,int father){
	dfn[x]=low[x]=++nowtime;
	s.push(x);
	for(register int i=head[x];i;i=e[i].next){
		int v(e[i].to);
		if(!dfn[v]){
			tarjan(v,i);
			low[x]=Min(low[x],low[v]);
		}else if(i!=(father^1))low[x]=Min(low[x],dfn[v]);
	}
	if(dfn[x]==low[x]){
		++dcccnt;
		int k;
		do{
			k=s.pop();
            out[dcccnt].push_back(k);
		}while(k!=x);
	}
}
inline void read(int &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
}
int main(){
	int n,m,u,v;
	read(n),read(m);
	for(register int i=1;i<=m;++i){
		read(u),read(v);
		add(u,v);
	}
	for(register int i=1;i<=n;++i)
		if(!dfn[i])tarjan(i,i);
    cout<<dcccnt<<endl;
    for(register int i=1;i<=dcccnt;++i){
        cout<<out[i].size()<<" ";
        for(auto j:out[i])
            cout<<j<<" ";
        cout<<endl;
    }
}