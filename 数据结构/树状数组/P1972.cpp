#include<bits/stdc++.h>
#define lowbit(x) x&(-x)
using namespace std;
int n,m,nowptr=1,c[1000005],a[1000005],vis[1000005];
struct edge{
    int l,r,id,ans;
}node[1000005];
inline void update(int k,int v){
    while(k<=n){
        c[k]+=v;
        k+=lowbit(k);
    }
}
inline int query(int p){
    int sum(0);
    while(p){
        sum+=c[p];
        p-=lowbit(p);
    }
    return sum;
}
inline bool cmpa(edge a,edge b){
    return a.r<b.r;
}
inline bool cmpb(edge a,edge b){
    return a.id<b.id;
}
inline void stream(int pos){
    for(;nowptr<=pos;++nowptr){
        if(vis[a[nowptr]]){
            update(vis[a[nowptr]],-1);
            update(nowptr,1);
            vis[a[nowptr]]=nowptr;
        }else{
            update(nowptr,1);
            vis[a[nowptr]]=nowptr;
        }
    }
}
int main(){
    cin>>n;
    for(register int i=1;i<=n;++i)cin>>a[i];
    cin>>m;
    for(register int i=1;i<=m;++i){
        cin>>node[i].l>>node[i].r;
        node[i].id=i;
    }
    sort(node+1,node+m+1,cmpa);
    for(register int i=1;i<=m;++i){
        if(nowptr<=node[i].r)stream(node[i].r);
        node[i].ans=query(node[i].r)-query(node[i].l-1);
    }
    sort(node+1,node+m+1,cmpb);
    for(register int i=1;i<=m;++i)cout<<node[i].ans<<endl;
}