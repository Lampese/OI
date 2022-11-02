#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
int n,m,k,a[MAXN][MAXN],b[MAXN][MAXN],c[MAXN][MAXN];
int main(){
    cin>>n>>m>>k;
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=m;++j)
            cin>>a[i][j];
    for(register int i=1;i<=m;++i)
        for(register int j=1;j<=k;++j)
            cin>>b[i][j];
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=k;++j)
            for(register int l=1;l<=m;++l)
                c[i][j]+=a[i][l]*b[l][j];
    for(register int i=1;i<=n;++i){
        for(register int j=1;j<=k;++j)
            cout<<c[i][j]<<" ";
        cout<<endl;
    }
}