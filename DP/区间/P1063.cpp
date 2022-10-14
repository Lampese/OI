#include<bits/stdc++.h>
#define MAXN 205
using namespace std;
int n,ans,a[MAXN],f[MAXN][MAXN];
int main(){
    cin>>n;
    for(register int i=1;i<=n;++i){
        cin>>a[i];
        a[i+n]=a[i];
    }
    a[0]=a[n];
    for(register int l=2;l<=n;++l)
        for(register int i=1;i+l-1<=2*n;++i){
            int j=i+l-1;
            if(j==i+1){
                f[i][j]=a[i]*a[j]*a[j+1];
            }else{
                f[i][j]=0;
                for(register int k=i;k<j;++k)
                    f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+a[i]*a[k+1]*a[j+1]);
            }
        }
    for(register int i=1;i<=n;++i)
        ans=max(ans,f[i][i+n-1]);
    cout<<ans<<endl;
}