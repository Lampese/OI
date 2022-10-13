#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
int n,m,t,cnt;
int a[MAXN],b[MAXN],T[MAXN];
int L[MAXN<<5],R[MAXN<<5],sum[MAXN<<5];
inline int build(int l,int r){
    int rt=++cnt;
    sum[rt]=0;
    if(l<r){
        int mid=(l+r)>>1;
        L[rt]=build(l,mid);
        L[rt]=build(mid+1,r);
    }
    return rt;
}
inline int update(int from,int l,int r,int x){
    int rt=++cnt;
    L[rt]=L[from];
    R[rt]=R[from];
    sum[rt]=sum[from]+1;
    if(l<r){
        int mid=(l+r)>>1;
        if(x<=mid)L[rt]=update(L[from],l,mid,x);
        else R[rt]=update(R[from],mid+1,r,x);
    }
    return rt;
}
inline int query(int u,int v,int l,int r,int k){
    if(l==r)return l;
    int left=sum[L[v]]-sum[L[u]],mid=(l+r)>>1;
    if(k<=left)return query(L[u],L[v],l,mid,k);
    else return query(R[u],R[v],mid+1,r,k-left);
}
int main(){
    cin>>n>>t;
    for(register int i=1;i<=n;++i){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    m=unique(b+1,b+n+1)-b-1;
    T[0]=build(1,m);
    for(register int i=1;i<=n;++i){
        int p=lower_bound(b+1,b+m+1,a[i])-b;
        T[i]=update(T[i-1],1,m,p);
    }
    while(t--){
        int x,y,z;
        cin>>x>>y>>z;
        int p=query(T[x-1],T[y],1,m,z);
        cout<<b[p]<<endl;
    }
}