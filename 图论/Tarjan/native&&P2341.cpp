#include<bits/stdc++.h>
#define MAXN 50050
#define Min(a,b) a<b?a:b
using namespace std;
int head[MAXN],dfn[MAXN],low[MAXN],num[MAXN],belong[MAXN],chu[MAXN];
int ecnt(0),nowtime(0),cnt(0);
struct mystack{
    int values[MAXN],top=0;
    bitset<MAXN>instack;
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
inline void add(int u,int v){
    e[++ecnt]={u,v,head[u]};
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
        ++cnt;
        int k(0);
        do{
            k=s.pop();
            ++num[cnt];
            belong[k]=cnt;
        }while(k!=x);
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
    for(register int i=1;i<=m;++i)
        if(belong[e[i].from]!=belong[e[i].to])
            ++chu[belong[e[i].from]];
    int sum(0),ans;
    for(int i=1;i<=cnt;++i)
        if(!chu[i])ans=num[i],++sum;
    if(sum>=2)printf("0");
    else printf("%d",ans);
    return 0;
}