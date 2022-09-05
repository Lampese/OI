#include<iostream>
#include<cstdio>
using namespace std;
int n,m,p,fa[5005],rankt[5005],x,y;
inline void read(int &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
}
inline void init(){
    for(register int i=1;i<=n;++i){
        fa[i]=i;
        rankt[i]=1;
    }
}
int find(int x){
    return x==fa[x]?x:(fa[x]=find(fa[x]));
}
inline void marge(int i,int j){
    int a=find(i),b=find(j);
    if(rankt[a]<=rankt[b])fa[a]=b;
    else fa[b]=a;
    if(rankt[a]==rankt[b]&&a!=b)++rankt[b];
}
int main(){
    read(n),read(m),read(p);
    init();
    for(register int i=1;i<=m;++i){
        read(x),read(y);
        marge(x,y);
    }
    for(register int i=1;i<=p;++i){
        read(x),read(y);
        if(find(x)==find(y))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}