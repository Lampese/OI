#include<bits/stdc++.h>
#define MAXN 300005
using namespace std;
long long n,m,u,cnt,arr[MAXN],d[MAXN],belong[MAXN],l[MAXN],r[MAXN];
inline void build(){
    long long blocksize=sqrt(n),cnt=n/blocksize;
    if(n%blocksize)++cnt;
    for(long long i=1;i<=cnt;++i){
        l[i]=blocksize*(i-1)+1;
        r[i]=blocksize*i;
    }
    r[cnt]=n;
    for(long long i=1;i<=n;++i){
        belong[i]=(i-1)/blocksize+1;
        d[i]=arr[i];
    }
    for(long long i=1;i<=cnt;++i)sort(d+l[i],d+r[i]+1);
}
inline void modify(long long k,long long v){
    long long block=belong[k];
    arr[k]=v;
    for(register long long i=l[block];i<=r[block];++i)d[i]=arr[i];
    sort(d+l[block],d+r[block]+1);
}
inline long long logalgor(long long block,long long k){
    long long L=l[block],R=r[block];
    if(d[L]>=k)return 0;
    while(L<R){
        long long mid=(L+R)>>1;
        if(d[mid]>=k)R=mid;
        else L=mid+1;
    }
    if(L==r[block]&&d[L]<k)return (r[block]-l[block]+1);
    return L-l[block];
}
inline long long find(long long L,long long R,long long k){
    long long ans=0;
    if(belong[L]==belong[R]){
        for(long long i=L;i<=R;++i)
            if(arr[i]<k)
                ++ans;
        return ans;
    }
    for(long long i=L;i<=r[belong[L]];++i)
        if(arr[i]<k)
            ++ans;
    for(long long i=belong[L]+1;i<belong[R];++i)ans+=logalgor(i,k);
    for(long long i=l[belong[R]];i<=R;++i)
        if(arr[i]<k)
            ++ans;
    return ans;
}
signed main(){
    long long L,R,V,P;
    cin>>n>>m>>u;
    for(register long long i=1;i<=n;++i)cin>>arr[i];
    build();
    while(m--){
        cin>>L>>R>>V>>P;
        long long ans=find(L,R,V);
        modify(P,u*ans/(R-L+1));
    }
    for(register long long i=1;i<=n;++i)cout<<arr[i]<<endl;
}