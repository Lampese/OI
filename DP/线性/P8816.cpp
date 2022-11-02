#include<bits/stdc++.h>
#define int long long
#define MAXN 505
using namespace std;
int n,k,dp[MAXN][105];
struct point{
    int x,y;
}p[MAXN];
inline int cost(int a,int b){
    return (p[a].x-p[b].x)+(p[a].y-p[b].y);
}
inline bool cmp(const point &a,const point &b){
    if(a.x==b.x)return a.y<b.y;
    else return a.x<b.x;
}
signed main(){
    cin>>n>>k;
    for(register int i=1;i<=n;++i)cin>>p[i].x>>p[i].y;
    sort(p+1,p+1+n,cmp);
    for(register int i=1;i<=n;++i){
        dp[i][0]=1;
        for(register int j=1;j<i;++j)
            if(p[i].y>=p[j].y){
                int dis=cost(i,j);
                for(register int l=0;l+dis-1<=k;++l)
                    dp[i][l+dis-1]=max(dp[i][l+dis-1],dp[j][l]+dis);
            }
    }
    int ans=-1;
    for(register int i=1;i<=n;++i)
        for(register int j=0;j<=k;++j)
            ans=max(ans,dp[i][j]+k-j);
    cout<<ans<<endl;
}