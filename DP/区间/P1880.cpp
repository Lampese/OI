#include<bits/stdc++.h>
using namespace std;
#define MAXN 105
const int inf=1000000005;
int n,a[MAXN<<1],sum[MAXN<<1];
int ffmax[MAXN<<1][MAXN<<1],ffmin[MAXN<<1][MAXN<<1];
int main(){
    cin>>n;
    for(register int i=1;i<=n;++i){
        cin>>a[i];
        a[i+n]=a[i];
    }
    for(register int i=1;i<=(n*2);++i){
        sum[i]=sum[i-1]+a[i];
        ffmax[i][i]=0;
        ffmin[i][i]=0;
    }
    for(register int l=2;l<=n;++l){
        for(register int i=1;i+l-1<=(n*2);++i){
            int j=i+l-1;
            ffmax[i][j]=0,ffmin[i][j]=inf;
            for(register int k=i;k<j;++k){
                ffmax[i][j]=max(ffmax[i][j],ffmax[i][k]+ffmax[k+1][j]);
                ffmin[i][j]=min(ffmin[i][j],ffmin[i][k]+ffmin[k+1][j]);
            }
            ffmax[i][j]+=sum[j]-sum[i-1];
            ffmin[i][j]+=sum[j]-sum[i-1];
        }
    }
    int ansmax=0,ansmin=inf;
    for(register int i=1;i<=n;++i){
        ansmax=max(ansmax,ffmax[i][i+n-1]);
        ansmin=min(ansmin,ffmin[i][i+n-1]);
    }
    cout<<ansmin<<endl<<ansmax<<endl;
}