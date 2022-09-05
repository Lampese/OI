#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
inline void read(int &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
}
int n,m,ans(0),cnt(0),fa[5005];
struct edge{
    int u,v,w;
}e[200005];
int find(int x){
    return x==fa[x]?x:(fa[x]=find(fa[x]));
}
bool cmp(const edge &x,const edge &y){
    return x.w<y.w;
}
void kruskal(){
    sort(e+1,e+m+1,cmp);
    for(register int i=1;i<=n;++i)fa[i]=i;
    for(register int i=1;i<=m;++i){
        int u=find(e[i].u),v=find(e[i].v);
        if(u!=v){
            ans+=e[i].w;
            fa[u]=v;
            ++cnt;
        }
        if(cnt==n-1)return;
    }
}
int main(){
    read(n),read(m);
    for(register int i=1;i<=m;++i)read(e[i].u),read(e[i].v),read(e[i].w);
    kruskal();
    if(cnt==n-1)cout<<ans<<endl;
    else cout<<"orz"<<endl;
    return 0;
}