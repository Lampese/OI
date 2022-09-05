#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int m=0,A,B,fa[1005],ans=0,cnt=0,num=0;
inline void init(){
    for(register int i=1;i<=B;++i)fa[i]=i;
}
int find(int x){
    return x==fa[x]?x:(fa[x]=find(fa[x]));
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
struct edge{
    int u,v,w;
}e[200005];
bool cmp(const edge &x,const edge &y){
    return x.w<y.w;
}
inline void Kruskal(){
    sort(e+1,e+1+m,cmp);
    init();
    for(register int i=1;i<=m-num;++i){
        int u=find(e[i].u),v=find(e[i].v);
        if(u!=v){
            ans+=e[i].w;
            fa[u]=v;
            ++cnt;
        }
    }
}
int main(){
    read(A),read(B);
    int w;
    for(register int i=1;i<=B;++i)
        for(register int j=1;j<=B;++j){
            read(w);
            if(i>j||w==0)continue;
            e[++m].u=i;
            e[m].v=j;
            e[m].w=w;
            if(e[m].w>A)++num;
        }
    Kruskal();
    if(cnt==B-1)cout<<ans+A<<endl;
    else cout<<ans+(B-cnt)*A<<endl;;
    return 0;
}