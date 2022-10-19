#include<bits/stdc++.h>
#define MAXN 55
using namespace std;
int n,c,p[MAXN],w[MAXN],sum[MAXN],f[MAXN][MAXN][2];
int main(){
    cin>>n>>c;
    memset(f,127,sizeof f);
    for(register int i=1;i<=n;++i){
        cin>>p[i]>>w[i];
        sum[i]=sum[i-1]+w[i]; 
    }
    f[c][c][0]=f[c][c][1]=0;
    for(register int l=2;l<=n;++l){
        for(register int i=1;i+l-1<=n;++i){
            int j=i+l-1;
            f[i][j][0]=min(f[i+1][j][0]+(p[i+1]-p[i])*(sum[n]+sum[i]-sum[j]),
                           f[i+1][j][1]+(p[j]-p[i])*(sum[n]+sum[i]-sum[j]));
            f[i][j][1]=min(f[i][j-1][1]+(p[j]-p[j-1])*(sum[n]+sum[i-1]-sum[j-1]),
                           f[i][j-1][0]+(p[j]-p[i])*(sum[n]+sum[i-1]-sum[j-1]));
        }
    }
    cout<<min(f[1][n][0],f[1][n][1]);
}