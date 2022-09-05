#include<cstdio>
#define MAXN 50050
using namespace std;
int head[MAXN],dfn[MAXN],low[MAXN];
int ecnt(0),nowtime(0),ans(0);
struct mystack{
    int values[MAXN],top=0;
    bool instack[MAXN]={false};
    inline int pop(){
        instack[values[--top]]=false;
        return values[top];
    }
    inline void push(int x){
        values[top++]=x;
        instack[x]=true;
    }
}s;
struct edge{
    int from,to,next;
}e[MAXN];
inline int Min(int a,int b){
    int diff=b-a;
    return a+(diff&(diff>>31));
}
inline void add(int u,int v){
    e[++ecnt].to=v;
    e[ecnt].from=u;
    e[ecnt].next=head[u];
    head[u]=ecnt;
}
void tarjan(int x){
    dfn[x]=low[x]=++nowtime;
    s.push(x);
    for(register int i=head[x];i;i=e[i].next){
        int v(e[i].to);
        if(s.instack[v])low[x]=Min(low[x],low[v]);
        if(!dfn[v]){
            tarjan(v);
            low[x]=Min(low[x],low[v]);
        }
    }
    if(dfn[x]==low[x]){
		int cnt(0);
        do ++cnt;
		while(s.pop()!=x);
		if(cnt>1)++ans;
    }
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
int main(){
    int n,m,u,v;
    read(n),read(m);
    for(register int i=1;i<=m;++i){
        read(u),read(v);
        add(u,v);
    }
    for(register int i=1;i<=n;++i)
        if(!dfn[i])tarjan(i);
    printf("%d",ans);
    return 0;
}