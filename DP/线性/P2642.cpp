#include<bits/stdc++.h>
using namespace std;
long long n,arr[1000005],f[1000005][3][2];
int main(){
    cin>>n;
    for(register int i=1;i<=n;++i)cin>>arr[i];
    memset(f,-0x7f,sizeof f);
    f[1][1][1]=arr[1],f[1][0][0]=0;
    for(register int i=2;i<=n;++i)
        for(register int j=0;j<=2;++j){
            f[i][j][0]=max(f[i-1][j][1],f[i-1][j][0]);
            if(j)f[i][j][1]=max(f[i-1][j][1]+arr[i],f[i-1][j-1][0]+arr[i]);
        }
    cout<<max(f[n][2][1],f[n][2][0])<<endl;
}