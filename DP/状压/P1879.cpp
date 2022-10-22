#include<bits/stdc++.h>
using namespace std;
const long long P=100000000;
long long n,m,ans;
long long init[13][13],cango[(1<<12)+10],_map[(1<<12)+10],f[13][(1<<12)+10];
int main(){
    cin>>n>>m;
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=m;++j)
            cin>>init[i][j];
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=m;++j)
            _map[i]=(_map[i]<<1)+init[i][j];
    for(register int i=0;i<(1<<m);++i)
        if(!(i&(i<<1))){
            cango[i]=1;
            if((i&_map[1])==i)f[1][i]=1;
        }
    for(register int i=2;i<=n;++i)
        for(register int j=0;j<(1<<m);++j)
            if(cango[j]&&((j&_map[i-1])==j))
                for(register int k=0;k<(1<<m);++k)
                    if(cango[k]&&((k&_map[i])==k)&&!(j&k)){
                        f[i][k]=(f[i][k]+f[i-1][j])%P;
                    }
    for(register int i=0;i<(1<<m);++i)
        ans=(ans+f[n][i])%P;
    cout<<ans<<endl;
    rerturn EXIT_SUCCESS
}