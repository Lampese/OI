#include<bits/stdc++.h>
using namespace std;
#define MAXN 3005
bitset<MAXN>vis[MAXN];
int n,ans=1e9,f[MAXN];
struct segment{
    int l,r;
}s[MAXN];
inline bool check(int a,int b){
    if(a<=0||b<=0||a>n||b>n)return false;
    return s[a].l<=s[b].r&&s[a].r>=s[b].l;
}
inline bool cmp(segment &a,segment &b){
    return a.r<b.r;
}
int main(){
    cin>>n;
    for(register int i=1;i<=n;++i)cin>>s[i].l>>s[i].r;
    sort(s+1,s+n+1,cmp);
    for(register int i=1;i<=n;++i){
        int flag=0;
        for(register int j=i;j<=n;++j){
            if(!check(j,i-1))
                if(!flag)
                    flag=j;
            if(flag)
                if(!check(flag,j+1)){
                    vis[i][j]=false;
                    continue;
                }
            vis[i][j]=true;
        }
        vis[i][i-1]=true;
    }
    vis[n+1][n]=true;
    for(register int i=1;i<=n;++i){
        f[i]=1e9;
        for(register int j=i-1;j>=0;--j){
            if(!check(i,j)){
                if(vis[j+1][i-1]){
                    f[i]=min(f[i],f[j]);
                }
            }
        }
        f[i]+=(s[i].r-s[i].l);
        if(vis[i+1][n])ans=min(ans,f[i]);
    }
    cout<<ans<<endl;
}