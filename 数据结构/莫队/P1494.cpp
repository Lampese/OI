#include<bits/stdc++.h>
#define int long long
#define MAXN 50005
using namespace std;
int n,m,l,r,now,a[MAXN],b[MAXN],belong[MAXN],ansa[MAXN],ansb[MAXN];
struct node{
    int l,r,id;
}q[MAXN];
inline void build(){
    int blocksize=sqrt(m);
    for(register int i=1;i<=n;++i)belong[i]=(i-1)/blocksize+1;
}
inline bool cmp(const node &a,const node &b){
    return (belong[a.l]==belong[b.l])?(belong[a.l]&1?a.r<b.r:a.r>b.r):belong[a.l]<belong[b.l];
}
inline void add(int x){
    now-=(b[a[x]]*b[a[x]]);
    ++b[a[x]];
    now+=(b[a[x]]*b[a[x]]);
}
inline void del(int x){
    now-=(b[a[x]]*b[a[x]]);
    --b[a[x]];
    now+=(b[a[x]]*b[a[x]]);
}
inline void update(int x){
    if(now==0){
        ansa[q[x].id]=0;
        ansb[q[x].id]=1;
        return;
    }
    int a=now-(r-l+1),b=(r-l+1)*(r-l),k=__gcd(a,b);
    ansa[q[x].id]=a/k,ansb[q[x].id]=b/k;
}
signed main(){
    cin>>n>>m;
    for(register int i=1;i<=n;++i)cin>>a[i];
    build();
    for(register int i=1;i<=m;++i){
        cin>>q[i].l>>q[i].r;
        q[i].id=i;
    }
    sort(q+1,q+1+m,cmp);
    l=q[1].l,r=q[1].r;
    for(register int i=l;i<=r;++i)add(i);
    update(1);
    for(register int i=2;i<=m;++i){
        if(q[i].l==q[i].r){
            ansa[q[i].id]=0;
            ansb[q[i].id]=1;
            continue;
        }
        while(l<q[i].l)del(l++);
        while(l>q[i].l)add(--l);
        while(r<q[i].r)add(++r);
        while(r>q[i].r)del(r--);
        update(i);
    }
    for(register int i=1;i<=m;++i){
        cout<<ansa[i]<<"/"<<ansb[i]<<endl;
    }
}