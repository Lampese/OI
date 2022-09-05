#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
    x=0;
    char ch=getchar();
	while(ch<47)ch=getchar();
	while(ch>47){
        x=x*10+ch-48;
        ch=getchar();
    }
}
int Max[100005][20];
inline int search(int l,int r){
    int k=log2(r-l+1);
    return min(Max[l][k],Max[r-(1<<k)+1][k]);
}
int main(){
    int n,m,l,r;
    read(n),read(m);
    for(register int i=1;i<=n;++i)read(Max[i][0]);
    for(register int j=1;j<=17;++j)
        for(register int i=1;i+(1<<j)-1<=n;++i)
            Max[i][j]=min(Max[i][j-1],Max[i+(1<<(j-1))][j-1]);
    for(register int i=1;i<=n-m+1;++i)
        printf("%d\n",search(i,m+i-1));
}