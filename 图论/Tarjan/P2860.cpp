#include<bits/stdc++.h>
using namespace std;
#define Min(a,b) a<b?a:b
#define MAXN 1000005
int dfn[MAXN],low[MAXN],head[MAXN],belong[MAXN],du[MAXN];
int ecnt(1),nowtime,dcccnt,ans;
struct edge{
	int from,to,next;
}e[MAXN];
inline void add(int u,int v){
	e[++ecnt]={u,v,head[u]},head[u]=ecnt;
    e[++ecnt]={v,u,head[v]},head[v]=ecnt;
}
struct mystack{
    int values[MAXN],ttop=0;
    inline void push(int x){
        values[ttop++]=x;
    }
    inline int pop(){
        return values[--ttop];
    }
    inline int top(){
        return values[ttop-1];
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
        belong[x]=++dcccnt;
        while(s.top()!=x)belong[s.pop()]=dcccnt;
        s.pop();
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
    for(register int i=1;i<=ecnt;++i){
		if(!(i&1))continue;
		if(belong[e[i].from]!=belong[e[i].to])
            ++du[belong[e[i].from]],++du[belong[e[i].to]];
	}
    for(register int i=1;i<=dcccnt;++i)
        if(du[i]==1)++ans;
    cout<<(ans+1>>1);
}