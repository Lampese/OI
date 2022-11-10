#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
int n,m,nowans,a[MAXN],s[MAXN],b[MAXN],t[MAXN],belong[MAXN],ans[MAXN];
struct node{
    int l,r,id;
}q[MAXN];
inline bool cmp(node &a,node &b){
    return belong[a.l]==belong[b.l]?belong[a.l]&1?a.r<b.r:a.r>b.r:belong[a.l]<belong[b.l];
}
inline void build(){
    int blocksize=sqrt(n);
    for(register int i=1;i<=n;++i)belong[i]=(i-1)/blocksize+1;
}
inline void add(int x){
    --t[b[x]];
    ++t[++b[x]];
    nowans=max(nowans,b[x]);
}
inline void del(int x){
    --t[b[x]];
    if(t[b[x]]==0&&nowans==b[x])--nowans;
    ++t[--b[x]];
}
inline void update(int x){
    ans[q[x].id]=nowans;
}
int main(){
    cin>>n>>m;
    for(register int i=1;i<=n;++i){
        cin>>a[i];
        s[i]=a[i];
    }
    build();
    sort(s+1,s+n+1);
    int len=unique(s+1,s+n+1)-s-1;
    for(register int i=1;i<=n;++i)a[i]=lower_bound(s+1,s+len+1,a[i])-s;
    for(register int i=1;i<=m;++i){
        cin>>q[i].l>>q[i].r;
        q[i].id=i;
    }
    sort(q+1,q+m+1,cmp);
    int L=1,R=0;
    for(register int i=1;i<=m;++i){
        while(L<q[i].l)del(a[L++]);
        while(L>q[i].l)add(a[--L]);
        while(R<q[i].r)add(a[++R]);
        while(R>q[i].r)del(a[R--]);
        update(i);
    }
    for(register int i=1;i<=m;++i)cout<<-ans[i]<<endl;
}