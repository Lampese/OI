#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,m,t,L=1,R=0,arr[MAXN],b[MAXN],belong[MAXN];
bool ans[MAXN];
struct node{
    int l,r,id;
}q[MAXN];
inline bool cmp(const node &a,const node &b){
    return (belong[a.l]==belong[b.l])?(belong[a.l]&1?a.r<b.r:a.r>b.r):belong[a.l]<belong[b.l];
}
inline void build(){
    int blocksize=sqrt(n);
    for(register int i=1;i<=n;++i)belong[i]=(i-1)/blocksize+1;
}
inline void add(int x){
    if(++b[x]==2)++t;
}
inline void del(int x){
    if(--b[x]==1)--t;
}
inline void update(int x){
    ans[q[x].id]=(t==0);
}
int main(){
    cin>>n>>m;
    build();
    for(register int i=1;i<=n;++i)cin>>arr[i];
    for(register int i=1;i<=m;++i){
        cin>>q[i].l>>q[i].r;
        q[i].id=i;
    }
    sort(q+1,q+1+m,cmp);
    for(register int i=1;i<=m;++i){
        while(L<q[i].l)del(arr[L++]);
        while(L>q[i].l)add(arr[--L]);
        while(R<q[i].r)add(arr[++R]);
        while(R>q[i].r)del(arr[R--]);
        update(i);
    }
    for(register int i=1;i<=m;++i)cout<<(ans[i]==true?"Yes":"No")<<endl;
}