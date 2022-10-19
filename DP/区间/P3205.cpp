#include<bits/stdc++.h>
#define MAXN 1005
using namespace std;
long long n,arr[MAXN],f[MAXN][MAXN][2];
signed main(){
    cin>>n;
    for(register long long i=1;i<=n;++i){
        cin>>arr[i];
        f[i][i][0]=1;
    }
    for(register long long len=1;len<=n;++len){
        for(register long long i=1;i+len-1<=n;++i){
            long long j=i+len-1;
            if(arr[j]>arr[j-1])f[i][j][1]+=f[i][j-1][1];
            if(arr[j]>arr[i])f[i][j][1]+=f[i][j-1][0];
            f[i][j][1]%=19650827;
            if(arr[i]<arr[j])f[i][j][0]+=f[i+1][j][1];
            if(arr[i]<arr[i+1])f[i][j][0]+=f[i+1][j][0];
            f[i][j][0]%=19650827;
        }
    }
    cout<<(f[1][n][0]+f[1][n][1])%19650827;
}