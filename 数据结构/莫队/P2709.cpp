#include<bits/stdc++.h>
#define MAXN 50005
using namespace std;
int n,m,k,nowans,L=1,R=0,a[MAXN],b[MAXN],belong[MAXN],ans[MAXN];
struct node{
    int l,r,id;
}q[MAXN];
inline bool cmp(const node &a,const node &b){
    return (belong[a.l]==belong[b.l])?((belong[a.l])&1?(a.r<b.r):(a.r>b.r)):belong[a.l]<belong[b.l];
}
inline void build(){
    int blocksize=sqrt(n);
    for(register int i=1;i<=n;++i)belong[i]=(i-1)/blocksize+1;
}
inline void add(int x){
    nowans-=(b[x]*b[x]);
    ++b[x];
    nowans+=(b[x]*b[x]);
}
inline void del(int x){
    nowans-=(b[x]*b[x]);
    --b[x];
    nowans+=(b[x]*b[x]);
}
inline void update(int x){
    ans[q[x].id]=nowans;
}
int main(){
    cin>>n>>m>>k;
    for(register int i=1;i<=n;++i)cin>>a[i];
    build();
    for(register int i=1;i<=m;++i){
        cin>>q[i].l>>q[i].r;
        q[i].id=i;   
    }
    sort(q+1,q+1+m,cmp);
    for(register int i=1;i<=m;++i){
        while(L<q[i].l)del(a[L++]);
        while(L>q[i].l)add(a[--L]);
        while(R<q[i].r)add(a[++R]);
        while(R>q[i].r)del(a[R--]);
        update(i);
    }
    for(register int i=1;i<=m;++i)
        cout<<ans[i]<<endl;
}