#include<bits/stdc++.h>
#define MAXN 2000005
#define Min(a,b) a<b?a:b
using namespace std;
int head[MAXN],dfn[MAXN],low[MAXN];
int nowtime,root,ecnt,dcccnt;
vector<int>dcc[MAXN];
struct mystack{
    int values[MAXN],top=0;
    inline void push(int x){
        values[top++]=x;
    }
    inline int pop(){
        return values[--top];
    }
}s;
struct edge{
    int to,next;
}e[MAXN<<1];
inline void add(int u,int v){
    e[++ecnt]={v,head[u]},head[u]=ecnt;
    e[++ecnt]={u,head[v]},head[v]=ecnt;
}
inline void read(int &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar();
	}
}
inline void tarjan(int x){
    dfn[x]=low[x]=++nowtime;
    s.push(x);
    if(x==root&&head[x]==0){
        dcc[++dcccnt].push_back(x);
        return;
    }
    for(register int i=head[x];i;i=e[i].next){
        int v(e[i].to);
        if(!dfn[v]){
            tarjan(v);
            low[x]=Min(low[x],low[v]);
            if(low[v]>=dfn[x]){ 
                ++dcccnt;
                int k;
                do{
                    k=s.pop();
                    dcc[dcccnt].push_back(k);
                }while(k!=v);
                dcc[dcccnt].push_back(x);
            }
        }else low[x]=Min(low[x],dfn[v]);
    }
}
int main(){
    int n,m,u,v;
    read(n),read(m);
    for(register int i=1;i<=m;++i){
        read(u),read(v);
        if(u==v)continue;
        add(u,v);
    }
    for(register int i=1;i<=n;++i)
        if(!dfn[i]){
            root=i;
            tarjan(i);
        }
    cout<<dcccnt<<endl;
    for(register int i=1;i<=dcccnt;++i){
        cout<<dcc[i].size()<<" ";
        for(register int j=0;j<dcc[i].size();++j)
            printf("%d ",dcc[i][j]);
        putchar('\n');   
    }
}