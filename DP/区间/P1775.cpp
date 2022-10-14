#include<bits/stdc++.h>
using namespace std;
#define MAXN 1005
const int inf=1000000005;
int n,a[MAXN<<1],sum[MAXN<<1];
int ffmin[MAXN<<1][MAXN<<1];
int main(){
    cin>>n;
    for(register int i=1;i<=n;++i)cin>>a[i];
    for(register int i=1;i<=n;++i){
        sum[i]=sum[i-1]+a[i];
        ffmin[i][i]=0;
    }
    for(register int l=2;l<=n;++l){
        for(register int i=1;i+l-1<=n;++i){
            int j=i+l-1;
            ffmin[i][j]=inf;
            for(register int k=i;k<j;++k)
                ffmin[i][j]=min(ffmin[i][j],ffmin[i][k]+ffmin[k+1][j]);
            ffmin[i][j]+=sum[j]-sum[i-1];
        }
    }
    cout<<ffmin[1][n];
}