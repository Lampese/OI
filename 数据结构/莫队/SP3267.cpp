#include<bits/stdc++.h>
#define MAXN 30005
using namespace std;
int n,m,now,a[MAXN],belong[MAXN],b[1000005],ans[200005];
struct node{
    int l,r,id;
}q[200005];
inline void build(){
    int blocksize=sqrt(m);
    for(register int i=1;i<=n;++i)belong[i]=(i-1)/blocksize+1;
}
inline bool cmp(const node &a,const node &b){
    return (belong[a.l]^belong[b.l])?belong[a.l]<belong[b.l]:(belong[a.l]&1?a.r<b.r:a.r>b.r);
}
inline void add(int x){
    if(!b[a[x]])++now;
    ++b[a[x]];
}
inline void del(int x){
    if(b[a[x]]==1)--now;
    --b[a[x]];
}
inline void update(int x){
    ans[q[x].id]=now;
}
int main(){
    scanf("%d",&n);
    for(register int i=1;i<=n;++i)scanf("%d",&a[i]);
    build();
    scanf("%d",&m);
    for(register int i=1;i<=m;++i){
        scanf("%d%d",&q[i].l,&q[i].r);
        q[i].id=i;
    }
    sort(q+1,q+m+1,cmp);
    int l=q[1].l,r=q[1].r;
    for(register int i=l;i<=r;++i)add(i);
    update(1);
    for(register int i=2;i<=m;++i){
        while(l<q[i].l)del(l++);
        while(l>q[i].l)add(--l);
        while(r<q[i].r)add(++r);
        while(r>q[i].r)del(r--);
        update(i);
    }
    for(register int i=1;i<=m;++i)cout<<ans[i]<<endl;
}