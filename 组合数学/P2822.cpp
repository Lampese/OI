#include<bits/stdc++.h>
#define MAXN 2005
using namespace std;
long long t,k,n,m,c[MAXN][MAXN],f[MAXN][MAXN];
int main(){
    cin>>t>>k;
    c[0][0]=c[1][0]=c[1][1]=1;
    for(register int i=2;i<=2000;++i){
        c[i][i]=c[i][0]=1;
        for(register int j=1;j<=i;++j)c[i][j]=(c[i-1][j]%k+c[i-1][j-1]%k)%k;
    }
    for(register int i=1;i<=2000;++i){
        for(register int j=1;j<=2000;++j)f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+(c[i][j]==0);
        f[i][i+1]=f[i][i];
    }
    for(register int i=1;i<=t;++i){
        cin>>n>>m;
        if(m>n)m=n;
        cout<<f[n][m]<<endl;
    }
}