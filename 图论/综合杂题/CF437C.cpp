#include<bits/stdc++.h>
using namespace std;
#define MAXN 2005
int n,m,u,v,ans,p[MAXN];
int main(){
    cin>>n>>m;
    for(register int i=1;i<=n;++i)cin>>p[i];
    for(register int i=1;i<=m;++i){
        cin>>u>>v;
        ans+=min(p[u],p[v]);
    }
    cout<<ans<<endl;
}