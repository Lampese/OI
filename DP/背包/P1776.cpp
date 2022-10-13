#include<bits/stdc++.h>
#define MAXN 4005
using namespace std;
int n,w,f[MAXN];
int main(){
    cin>>n>>w;
    for(register int i=1;i<=n;++i){
        int v,c,m;
        cin>>v>>c>>m;
        for(register int M=1;M<m;M<<=1){
            for(register int j=w;j>=M*c;--j)
                f[j]=max(f[j],f[j-M*c]+M*v);
            m-=M;
        }
        for(register int j=w;j>=m*c;--j)
            f[j]=max(f[j],f[j-m*c]+m*v);
    }
    cout<<f[w];
}