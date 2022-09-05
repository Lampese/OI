#include<iostream>
#include<cstdio>
#include<set>
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
#define MAXN 10000005
int n,m,l,r,arr[MAXN];
inline void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
inline void output(int l,int r,bool y){
    if(y)for(register int i=r;i>=l;--i)write(arr[i]),putchar(' ');
    else for(register int i=l;i<=r;++i)write(arr[i]),putchar(' ');
}
set<pair<int,int>>s;
int main(){
    read(n),read(m);
    for(register int i=1;i<=n;++i)read(arr[i]);
    for(register int i=1;i<=m;++i){
        read(l),read(r);
        s.insert({l,r});
    }
    int flag=1;
    for(auto it=s.begin();it!=s.end();++it){
        int ll((*it).first),rr((*it).second);
        if(flag<ll)output(flag,ll-1,0);
        output(ll,rr,1);
        flag=rr+1;
    }
    if(flag<=n)output(flag,n,0);
    return 0;
}