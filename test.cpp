#include<bits/stdc++.h>
using namespace std;
bool vis[200005];
long long arr[200005],t,n;
struct _{
    long long id,dead;
}d[200005];
inline bool cmp(_ a,_ b){
    return a.dead<b.dead;
}
inline long long kill(long long x){
    long long dd=d[x].dead;
    x=d[x].id;
    vis[x]=true;
    for(register long long i=x-1;i>=1;--i){
        if(vis[i]==false){
            arr[i]+=dd;
            break;
        }
    }
    for(register long long i=x+1;i<=n;++i){
        if(vis[i]==false){
            arr[i]+=dd;
            break;
        }
    }
    return arr[x];
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(register long long i=1;i<=n;++i)vis[i]=false;
        long long ans(0);
        for(register long long i=1;i<=n;++i){
            cin>>arr[i];
        }
        for(register long long i=1;i<=n;++i){
            cin>>d[i].dead;
            d[i].id=i;
        }
        sort(d+1,d+n+1,cmp);
        for(register long long i=1;i<=n;++i){
            ans+=kill(i);
        }
        cout<<ans<<endl;
    }
}