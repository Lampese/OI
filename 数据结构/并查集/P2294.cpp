#include<bits/stdc++.h>
#define MAXN 1005
using namespace std;
int q,n,m,u,v,w,fa[MAXN],dp[MAXN];
int find(int x){
    if(x!=fa[x]){
        int root=find(fa[x]);
        dp[x]+=dp[fa[x]];
        fa[x]=root;
    }
    return fa[x];
}
int main(){
    bool flag=true;
    cin>>q;
    while(q--){
        cin>>n>>m;
        for(register int i=0;i<=n;++i)fa[i]=i,dp[i]=0;
        flag=true;
        for(register int i=1;i<=m;++i){
            cin>>u>>v>>w;
            if(!flag)continue;
            --u;
            if(find(u)!=find(v)){
                dp[fa[v]]=dp[u]-dp[v]-w;
                fa[fa[v]]=fa[u];
            }
            else if(dp[u]-dp[v]!=w)flag=false;
        }
        if(flag)cout<<"true"<<endl;
        else cout<<"false"<<endl;
    }
}