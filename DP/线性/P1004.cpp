#include<bits/stdc++.h>
#define MAXN 11
using namespace std;
int n,Map[MAXN][MAXN],dp[MAXN][MAXN][MAXN][MAXN];
int main(){
    cin>>n;
    while(true){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==0&&b==0&&c==0)break;
        Map[a][b]=c;
    }
    for(register int a=1;a<=n;++a)
        for(register int b=1;b<=n;++b)
            for(register int c=1;c<=n;++c)
                for(register int d=1;d<=n;++d){
                    dp[a][b][c][d]=max(max(dp[a-1][b][c-1][d],dp[a-1][b][c][d-1]),max(dp[a][b-1][c-1][d],dp[a][b-1][c][d-1]))+Map[a][b]+Map[c][d];
                    if(a==c&&b==d)dp[a][b][c][d]-=Map[a][b];
                }
    cout<<dp[n][n][n][n];
}