#include<bits/stdc++.h>
using namespace std;
int fa[10005],rankt[10005],n,m,z,x,y;
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
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
inline void marge(int i,int j){
    int a=find(i),b=find(j);
    if(rankt[a]<=rankt[b])fa[a]=b;
    else fa[b]=a;
    if(rankt[a]==rankt[b]&&a!=b)++rankt[b];
}
int main(){
    read(n),read(m);
    init();
    for(register int i=1;i<=m;++i){
        read(z),read(x),read(y);
        if(z==1)marge(x,y);
        else if(find(x)==find(y))cout<<"Y"<<endl;
        else cout<<"N"<<endl;
    }
}