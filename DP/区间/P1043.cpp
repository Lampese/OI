#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
int n,m,a[MAXN],sum[MAXN],dpmin[MAXN][MAXN][11],dpmax[MAXN][MAXN][11];
inline int cost(int x,int y){
    return ((sum[y]-sum[x-1])%10+10)%10;
}
int main(){
    cin>>n>>m;
    for(register int i=1;i<=n;++i){
        cin>>a[i];
        a[n+i]=a[i];
    }
    for(register int i=1;i<=2*n;++i)sum[i]=sum[i-1]+a[i];
    for(register int l=1;l<=2*n;++l)
        for(register int r=l;r<=2*n;++r)
            dpmin[l][r][1]=dpmax[l][r][1]=cost(l,r);
    
    for(register int i=2;i<=m;++i)
        for(register int l=1;l<=2*n;++l)
            for(register int r=l+i-1;r<=2*n;++r){
                dpmin[l][r][i]=1000000000;
                for(register int k=l+i-2;k<r;++k){
                    dpmin[l][r][i]=min(dpmin[l][r][i],dpmin[l][k][i-1]*cost(k+1,r));
                    dpmax[l][r][i]=max(dpmax[l][r][i],dpmax[l][k][i-1]*cost(k+1,r));
                }
            }
    int ansmin=1000000000,ansmax=-1;
    for(register int i=1;i<=n;++i){
        ansmin=min(ansmin,dpmin[i][i+n-1][m]);
        ansmax=max(ansmax,dpmax[i][i+n-1][m]);
    }
    cout<<ansmin<<endl<<ansmax<<endl;
}