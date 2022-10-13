#include<bits/stdc++.h>
#define MAXN 20
using namespace std;
const int inf=100005;
int m,cnt,cost[MAXN],dp[100005];
int main(){
    cin>>m;
    for(register int i=1;;++i){
        int result=pow(i,4);
        if(result>m)break;
        else cost[++cnt]=result;
    }
    for(register int i=1;i<inf;++i)dp[i]=inf;
    for(register int i=1;i<=cnt;++i)
        for(register int j=cost[i];j<=m;++j)
            dp[j]=min(dp[j],dp[j-cost[i]]+1);
    cout<<dp[m]<<endl;
}