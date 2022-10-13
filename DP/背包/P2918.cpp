#include<bits/stdc++.h>
#define MAXN 105
const int inf=10000000;
using namespace std;
int n,h,sum,ans=inf,cost[MAXN],value[MAXN],f[500005];
int main(){
    cin>>n>>h;
    for(register int i=1;i<=n;++i)
        cin>>cost[i]>>value[i];
    f[0]=0;
    for(register int i=1;i<=500005;++i)f[i]=inf;
    for(register int i=1;i<=n;++i)
        for(register int j=cost[i];j<=500005;++j)
            f[j]=min(f[j],f[j-cost[i]]+value[i]);
    for(register int i=h;i<=500005;++i)
        ans=min(ans,f[i]);
    cout<<ans<<endl;
}