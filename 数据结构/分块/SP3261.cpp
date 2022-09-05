#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,m,cnt,arr[MAXN],d[MAXN],belong[MAXN],l[MAXN],r[MAXN];
inline void build(){
    int blocksize=sqrt(n),cnt=n/blocksize;
    if(n%blocksize)++cnt;
    for(int i=1;i<=cnt;++i)l[i]=blocksize*(i-1)+1,r[i]=blocksize*i;
    r[cnt]=n;
    for(int i=1;i<=n;++i){
        belong[i]=(i-1)/blocksize+1;
        d[i]=arr[i];
    }
    for(int i=1;i<=cnt;++i)sort(d+l[i],d+r[i]+1);
}
inline void modify(int k,int v){
    int block=belong[k];
    int L=l[block],R=r[block];
    arr[k]=v;
    for(register int i=L;i<=R;++i)d[i]=arr[i];
    sort(d+l[block],d+r[block]+1);
}
inline int logalgor(int block,int k){
    int L=l[block],R=r[block];
    if(d[L]>k)return 0;
    while(L<R){
        int mid=(L+R+1)>>1;
        if(d[mid]<=k)L=mid;
        else R=mid-1;
    }
    return L-l[block]+1;
}
inline int find(int L,int R,int k){
    int ans=0;
    if(belong[L]==belong[R]){
        for(int i=L;i<=R;++i)
            if(arr[i]<=k)
                ++ans;
        return ans;
    }
    for(int i=L;i<=r[belong[L]];++i)
        if(arr[i]<=k)
            ++ans;
    for(int i=belong[L]+1;i<belong[R];++i)ans+=logalgor(i,k);
    for(int i=l[belong[R]];i<=R;++i)
        if(arr[i]<=k)
            ++ans;
    return ans;
}
int main(){
    char opt;
    int q,L,R,v;
    cin>>n>>q;
    for(register int i=1;i<=n;++i)cin>>arr[i];
    build();
    while(q--){
        cin>>opt>>L>>R;
        if(opt=='M')modify(L,R);
        else{
            cin>>v;
            cout<<find(L,R,v)<<endl;
        }
    }
}