#include<iostream>
#include<cstdio>
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
int main(){
    read(n),read(m);
    for(register int i=1;i<=n;++i)read(arr[i]);
    for(register int i=1;i<=m;++i){
        read(l),read(r);
        for(register int j=l;j<=((l+r)/2);++j){
            swap(arr[j],arr[r-j+1+(l+r)/2]);
        }
    }
    for(register int i=1;i<=n;++i)write(arr[i]),putchar(' ');
    return 0;
}