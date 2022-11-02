#include<bits/stdc++.h>
#define MAXN 50005
using namespace std;
const long long P=987654321;
bitset<55>vis[MAXN];
long long n,m,c,ans,same[MAXN],f[MAXN][15];
inline void dp(){
    for(register long long i=2;i<=n+1;++i){
        if(same[i]){
            for(register long long j=1;j<=c;++j)
                if(vis[i][j])
                    f[i][j]=f[i-1][j];
        }else{
            for(register long long j=1;j<=c;++j){
                if(vis[i][j]){
                    for(register long long k=1;k<=c;++k){
                        if(k!=j)
                            f[i][j]=(f[i][j]+f[i-1][k])%P;
                    }
                }
            }
        }
    }
}
int main(){
    cin>>n>>m>>c;
    for(register long long i=1;i<=n+1;++i)
        for(register long long j=1;j<=c;++j)
            vis[i][j]=true;
    for(register long long i=1;i<=m;++i){
        long long opt,x,y;
        cin>>opt>>x>>y;
        if(opt==1){
            if(vis[x][y]==false){
                cout<<0<<endl;
                return 0;
            }
            for(register long long j=1;j<=c;++j)
                vis[x][j]=false;
            vis[x][y]=true;
        }else if(opt==2){
            vis[x][y]=false;
        }else{
            same[max(x,y)]=true;
        }
    }
    vis[n+1]=vis[1];
    for(register long long i=1;i<=c;++i){
        if(vis[1][i]){
            for(register long long k=1;k<=n+1;++k)
                for(register long long j=1;j<=c;++j)
                    f[k][j]=0;
            f[1][i]=1;
            dp();
            ans=(ans+f[n+1][i])%P;
        }
    }
    cout<<ans<<endl;
}