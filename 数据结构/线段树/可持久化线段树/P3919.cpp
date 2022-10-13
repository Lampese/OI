#include<bits/stdc++.h>
#define MAXN 1000005
using namespace std;
#define IN stdin->_IO_read_ptr<stdin->_IO_read_end?*stdin->_IO_read_ptr++:__uflow(stdin)
#define read_fs
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
int n,m,cnt,a[MAXN],T[MAXN],L[MAXN<<5],R[MAXN<<5],val[MAXN<<5];
inline int build(int l,int r){
    int rt=++cnt;
    if(l==r)val[rt]=a[l];
    else{
        int mid=(l+r)>>1;
        L[rt]=build(l,mid);
        R[rt]=build(mid+1,r);
    }
    return rt;
}
inline int update(int from,int l,int r,int k,int v){
    int rt=++cnt;
    if(l==r)val[rt]=v;
    else{
        L[rt]=L[from];
        R[rt]=R[from];
        int mid=(l+r)>>1;
        if(k<=mid)L[rt]=update(L[from],l,mid,k,v);
        else R[rt]=update(R[from],mid+1,r,k,v);
    }
    return rt;
}
inline int query(int from,int l,int r,int k){
    if(l==r)return val[from];
    int mid=(l+r)>>1;
    if(k<=mid)return query(L[from],l,mid,k);
    else return query(R[from],mid+1,r,k);
}
int main(){
    cin>>n>>m;
    for(register int i=1;i<=n;++i)read(a[i]);
    T[0]=build(1,n);
    int version,opt,x,y;
    for(register int i=1;i<=m;++i){
        read(version),read(opt);
        if(opt==1){
            read(x),read(y);
            T[i]=update(T[version],1,n,x,y);
        }else{
            read(x);
            T[i]=T[version];
            cout<<query(T[version],1,n,x)<<endl;
        }
    }
}