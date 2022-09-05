#include<bits/stdc++.h>
using namespace std;
#define MAXN 100010
int head[MAXN],m,x,y,ecnt(1);
bitset<MAXN>vis;
struct mystack{
    int values[MAXN],ttop=0;
    inline int top(){
        return values[ttop-1];
    }
    inline void push(int x){
        values[ttop++]=x;
    }
    inline void pop(){
        --ttop;
    }
    inline bool empty(){
        return ttop==0;
    }
}ans,stk;
struct edge{
    int to,next;
}e[MAXN];
inline void add(int u,int v){
    e[++ecnt]={v,head[u]},head[u]=ecnt;
    e[++ecnt]={u,head[v]},head[v]=ecnt;
}
void dfs1(){    
    stk.push(1);
    while(!stk.empty()){
        int x(stk.top()),i(head[x]);
        while(i&&vis[i])i=e[i].next;
        if(i){
            stk.push(e[i].to);
            vis[i]=vis[i^1]=true;
            head[x]=e[i].next;
        }else{
            stk.pop();
            ans.push(x);
        }
    }
}
void dfs2(int x){
    for(register int i=head[x];i;i=e[i].next){
        if(!vis[i]){
            vis[i]=vis[i^1]=1;
            dfs2(e[i].to);
            stk.push(e[i].to);
        }
    }
}
int main(){
    cin>>m;
    for(register int i=1;i<=m;++i){
        cin>>x>>y;
        add(x,y);
    }
    dfs1(1);
    while(!ans.empty()){
        cout<<ans.top()<<endl;
        ans.pop();
    }
}