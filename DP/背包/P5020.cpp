#include<bits/stdc++.h>
#define MAXN 30000
using namespace std;
int t,n,maxx=-1,a[105],f[MAXN];
int main(){
    cin>>t;
    while(t--){
        int ans(0);
        cin>>n;
        for(register int i=1;i<=n;++i){
            cin>>a[i];
            maxx=max(maxx,a[i]);
        }
        for(register int i=1;i<=maxx;++i)f[i]=-10000;
        f[0]=0;
        for(register int i=1;i<=n;++i)
            for(register int j=a[i];j<=maxx;++j)
                f[j]=max(f[j],f[j-a[i]]+1);
        for(register int i=1;i<=n;++i)
            if(f[a[i]]==1)++ans;
        cout<<ans<<endl;
    }
}