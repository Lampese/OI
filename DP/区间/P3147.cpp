#include<bits/stdc++.h>
#define MAXN 250
using namespace std;
int n,ans,a[MAXN],f[MAXN][MAXN];
int main(){
    cin>>n;
    for(register int i=1;i<=n;++i){
        cin>>a[i];
        f[i][i]=a[i];
        ans=max(ans,a[i]);
    }
    for(register int l=2;l<=n;++l)
        for(register int i=1;i+l-1<=n;++i){
            int j=i+l-1;
            for(register int k=1;k<j;++k){
                if(f[i][k]==f[k+1][j]){
                    f[i][j]=max(f[i][j],f[i][k]+1);
                    ans=max(ans,f[i][j]);
                }
            }
        }
    cout<<ans<<endl;
}