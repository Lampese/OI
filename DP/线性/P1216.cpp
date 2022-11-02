#include<bits/stdc++.h>
using namespace std;
int tr[1005][1005],f[1005][1005];
int main(){
    int n;
    cin>>n;
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=i;++j)
            cin>>tr[i][j];
    f[1][1]=tr[1][1];
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=i;++j)
            f[i][j]=max(f[i-1][j]+tr[i][j],f[i-1][j-1]+tr[i][j]);
    int ans=0;
    for(register int i=1;i<=n;++i)
        ans=max(ans,f[n][i]);
    cout<<ans<<endl;
}