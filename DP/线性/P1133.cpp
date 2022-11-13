#include<bits/stdc++.h>
using namespace std;
int ans,a[100005][3],f[100005][3][2];
int main(){
    int n;
    cin>>n;
    for(register int i=1;i<=n;++i)cin>>a[i][0]>>a[i][1]>>a[i][2];
    for(register int color=0;color<=2;++color){
        for(register int i=0;i<=2;++i)
            for(register int j=0;j<=1;++j)
                f[1][i][j]=0;
        f[1][color][0]=f[1][color][1]=a[1][color];
        for(register int i=2;i<=n;++i){
            f[i][0][1]=max(f[i-1][1][0],f[i-1][2][0])+a[i][0];
            f[i][1][0]=f[i-1][0][1]+a[i][1];
            f[i][1][1]=f[i-1][2][0]+a[i][1];
            f[i][2][0]=max(f[i-1][1][1],f[i-1][0][1])+a[i][2];
        }
        for(register int i=0;i<color;++i)ans=max(ans,f[n][i][1]);
        for(register int i=2;i>color;--i)ans=max(ans,f[n][i][0]);
    }
    cout<<ans<<endl;
}