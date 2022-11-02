#include<bits/stdc++.h>
using namespace std;
bool mm[10][10];
pair<int,int>vis[10];
int t,n,m;
inline void init(){
    for(register int i=1;i<=9;++i)
        for(register int j=1;j<=9;++j)
            mm[i][j]=false;
}
inline bool check(int x){
    init();
    mm[vis[x].first][vis[x].second]=true;
    for(register int i=1;i<=m;++i){
        if(i==x)continue;
        for(register int j=1;j<=n;++j)mm[vis[i].first][j]=mm[j][vis[i].second]=true;
    }
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=n;++j)
            if(mm[i][j]==false)
                return true;
    return false;
}
int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(register int i=1;i<=m;++i){
            int x,y;
            cin>>x>>y;
            vis[i]={x,y};
        }
        bool flag=false;
        for(register int i=1;i<=m;++i){
            if(check(i)){
                cout<<"YES"<<endl;
                flag=true;
                break;
            }
        }
        if(!flag)cout<<"NO"<<endl;
    }
}