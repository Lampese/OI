#include<bits/stdc++.h>
using namespace std;
int n,w,maxx=-1,minn=1000000005,v[105],p[105],dp[30005];
inline bool cmp(int x,int y){
    return x>y;
}
int main(){
    cin>>n>>w;
    for(register int i=1;i<=n;++i){
        cin>>v[i]>>p[i];
        maxx=max(maxx,v[i]);
        minn=min(minn,v[i]);
    }
    if(minn<=300){
        for(register int i=1;i<=n;++i)
            for(register int j=30000;j>=v[i];--j)
                dp[j]=max(dp[j],dp[j-v[i]]+p[i]);
        cout<<dp[w]<<endl;
    }else{
        int ans(0);
        sort(p+1,p+n+1,cmp);
        for(register int i=1;i<=w/maxx;++i)ans+=p[i];
        cout<<ans<<endl;
    }
}