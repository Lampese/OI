#include<bits/stdc++.h>
#define MAXN 2005
using namespace std;
int n,m,p,q,ans,f[MAXN];
char opt;
int find(int x){
    return x==f[x]?x:f[x]=find(f[x]);
}
int main(){
    deque<int>q;
    q.empty();
    for(register int i=1;i<MAXN;++i)f[i]=i;
    cin>>n>>m;
    for(register int i=1;i<=m;++i){
        cin>>opt>>p>>q;
        if(opt=='F')f[find(p)]=find(q);
        else f[find(n+p)]=find(q),f[find(n+q)]=find(p);
    }
    for(register int i=1;i<=n;++i)
        if(f[i]==i)++ans;
    cout<<ans<<endl;
}