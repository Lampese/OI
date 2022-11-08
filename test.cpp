#include<bits/stdc++.h>
#define MAXN 500005
int n,m,cnt,T[MAXN],L[MAXN],R[MAXN],sum[MAXN],ans[MAXN];
inline int build(int l,int r){
    int rt=++cnt;
    if(l<r){
        int mid=(l+r)>>1;
        L[rt]=build(l,mid);
        R[rt]=build(mid+1,r);
    }
    return rt;
}
inline int update(int from,int l,int r,int x){
    int rt=++cnt;
    L[rt]=L[from];
    R[rt]=R[from];
    
}
int main(){
    cin>>n>>m;

}