#include<bits/stdc++.h>
#define MAXN 500050
#define Min(a,b) a<b?a:b 
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
int head[MAXN],dfn[MAXN],low[MAXN],belong[MAXN],ru[MAXN];
int ecnt,nowtime,cnt;
struct egde{
	int u,v,next;
}e[MAXN];
inline void add(int u,int v){
	e[++ecnt]={u,v,head[u]};
	head[u]=ecnt;
}
struct mystack{
	int values[MAXN],top=0;
	bitset<MAXN>instack;
	inline void push(int x){
		instack[x]=true;
		values[top++]=x;
	}
	inline int pop(){
		instack[values[--top]]=false;
		return values[top];
	} 
}s;
void tarjan(int x){
	dfn[x]=low[x]=++nowtime;
	s.push(x);
	for(register int i=head[x];i;i=e[i].next){
		int v(e[i].v);
		if(s.instack[v])low[x]=Min(low[x],low[v]);
		if(!dfn[v]){
			tarjan(v);
			low[x]=Min(low[x],low[v]);
		}
	}
	if(dfn[x]==low[x]){
		++cnt;
		int k=0;
		do{
			k=s.pop();
			belong[k]=cnt;
		}while(k!=x);
	}
}
int main(){
	int n,u,v,temp,ans=0;
	read(n);
	for(register int i=1;i<=n;++i){
        read(temp);
        while(temp!=0){
            add(i,temp);
            read(temp);
        }
	}
	for(register int i=1;i<=n;++i)
		if(!dfn[i])tarjan(i);
	for(register int i=1;i<=ecnt;++i)
		if(belong[e[i].u]!=belong[e[i].v])
			++ru[belong[e[i].v]];
	for(register int i=1;i<=cnt;++i)
		if(ru[i]==0)++ans;
	cout<<ans<<endl;
}