#include<bits/stdc++.h>
#define MAXN 133339
using namespace std;
#define IN stdin->_IO_read_ptr<stdin->_IO_read_end?*stdin->_IO_read_ptr++:__uflow(stdin)
#define OUT(_ch) stdout->_IO_write_ptr<stdout->_IO_write_end?*stdout->_IO_write_ptr++=_ch:__overflow(stdout,_ch)
template<typename T>inline void read(T &x){
	x=0;
    #ifdef read_fs
    int w(1);
    #endif
	char ch=IN;
	while(ch<47){
        #ifdef read_fs
        if(ch=='-')w=-1;
        #endif
        ch=IN;
    }
	while(ch>47)x=(x<<1)+(x<<3)+(ch&15),ch=IN;
    #ifdef read_fs
    if(w<0)x=-x;
    #endif
}
template<typename T>void __print(T x){if(x>9)__print(x/10);OUT(x%10+48);}
int n,m,nowt,nowans,cnta,cntb,L=1,R=0,a[MAXN],b[1000005],belong[MAXN],ans[MAXN];
struct node{
    int l,r,t,id;
}q[MAXN];
inline bool cmp(const node &a,const node &b){
    return (belong[a.l]^belong[b.l])?belong[a.l]<belong[b.l]:(belong[a.r]^belong[b.r])?belong[a.r]<belong[b.r]:a.t<b.t;
}
struct Modify{
    int pos,value;
}p[MAXN];
inline void build(){
    int blocksize=pow(n,0.666);
    for(register int i=1;i<=n;++i)belong[i]=(i-1)/blocksize+1;
}
inline void add(int x){
    if(++b[x]==1)++nowans;
}
inline void del(int x){
    if(--b[x]==0)--nowans;
}
inline void update(int x){
    ans[q[x].id]=nowans;
}
inline void stream(int now,int i){
    if(q[i].l<=p[now].pos&&p[now].pos<=q[i].r){
        del(a[p[now].pos]);
        add(p[now].value);
    }
    swap(a[p[now].pos],p[now].value);
}
int main(){
    read(n),read(m);
    for(register int i=1;i<=n;++i)read(a[i]);
    for(register int i=1;i<=m;++i){
        int l,r;
        char op[5];
        scanf("%s", op);
        read(l),read(r);
        if(op[0]=='Q'){
            ++cnta;
            q[cnta]={l,r,cntb,cnta};
        }else p[++cntb]={l,r};
    }
    build();
    sort(q+1,q+cnta+1,cmp);
    for(register int i=1;i<=cnta;++i){
        while(L<q[i].l)del(a[L++]);
        while(L>q[i].l)add(a[--L]);
        while(R<q[i].r)add(a[++R]);
        while(R>q[i].r)del(a[R--]);
        while(nowt<q[i].t)stream(++nowt,i);
        while(nowt>q[i].t)stream(nowt--,i);
        update(i);
    }
    for(register int i=1;i<=cnta;++i)
        __print(ans[i]),OUT('\n');
}