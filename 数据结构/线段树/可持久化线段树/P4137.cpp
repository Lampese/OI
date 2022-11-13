#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
int n,m,cnt,len,arr[MAXN],b[MAXN<<2],T[MAXN],L[MAXN<<5],R[MAXN<<5],sum[MAXN<<5];
inline int build(int l,int r){
    int rt=++cnt;
    if(l<r){
        int mid=(l+r)>>1;
        L[rt]=build(l,mid);
        R[rt]=build(mid+1,r);
    }
    return rt;
}
inline int update(int from,int l,int r,int p,int x){
    int rt=++cnt;
    if(l==r)return sum[rt]=x,rt;
    if(l<r){
        L[rt]=L[from];
        R[rt]=R[from];
        int mid=(l+r)>>1;
        if(p<=mid)L[rt]=update(L[from],l,mid,p,x);
        else R[rt]=update(R[from],mid+1,r,p,x);
    }
    sum[rt]=min(sum[L[rt]],sum[R[rt]]);
    return rt; 
}
inline int query(int from,int l,int r,int x){
    if(l==r)return l;
    int mid=(l+r)>>1;
    if(sum[L[from]]>=x)return query(R[from],mid+1,r,x);
    else return query(L[from],l,mid,x);
}
int main(){
    cin>>n>>m;
    b[++len]=0;
    for(register int i=1;i<=n;++i){
        cin>>arr[i];
        b[++len]=arr[i],b[++len]=arr[i]+1;
    }
    sort(b+1,b+1+len);
    int id=unique(b+1,b+1+len)-b-1;
    T[0]=build(1,id);
    for(register int i=1;i<=n;++i){
        int pos=lower_bound(b+1,b+1+id,arr[i])-b;
        T[i]=update(T[i-1],1,id,pos,i);
    }
    //3 5 4 0
    while(m--){
        int u,v;
        cin>>u>>v;
        cout<<b[query(T[v],1,id,u)]<<endl;
    }
}