#include<bits/stdc++.h>
#define MAXN 1000005
using namespace std;
int n,m,cnt,arr[MAXN],d[MAXN],belong[MAXN],l[MAXN],r[MAXN],mark[MAXN];
inline void build(){
    int blocksize=sqrt(n),cnt=n/blocksize;
    if(n%blocksize)++cnt;
    for(int i=1;i<=cnt;++i){
        l[i]=blocksize*(i-1)+1;
        r[i]=blocksize*i;
    }
    r[cnt]=n;
    for(int i=1;i<=n;++i){
        belong[i]=(i-1)/blocksize+1;
        d[i]=arr[i];
    }
    for(int i=1;i<=cnt;++i)sort(d+l[i],d+1+r[i]);
}
inline void modify(int L,int R,int V){
    if(belong[L]==belong[R]){
        for(int i=L;i<=R;++i)arr[i]+=V;
        for(int i=l[belong[L]];i<=r[belong[L]];++i)d[i]=arr[i];
        sort(d+l[belong[L]],d+1+r[belong[L]]);
        return;
    }
    for(int i=L;i<=r[belong[L]];++i)arr[i]+=V;
    for(int i=l[belong[L]];i<=r[belong[L]];++i)d[i]=arr[i];
    sort(d+l[belong[L]],d+1+r[belong[L]]);
    for(int i=belong[L]+1;i<belong[R];++i)mark[i]+=V;
    for(int i=l[belong[R]];i<=R;++i)arr[i]+=V;
    for(int i=l[belong[R]];i<=r[belong[R]];++i)d[i]=arr[i];
    sort(d+l[belong[R]],d+1+r[belong[R]]);
}
inline int logalgor(int block,int k){
    int L=l[block],R=r[block];
    while(L<R){
        int mid=(L+R)>>1;
        if(d[mid]+mark[block]>=k)R=mid;
        else L=mid+1;
    }
    if(r[block]==L&&d[L]+mark[block]<k)return 0;
    return r[block]-L+1;
}
inline int find(int L,int R,int k){
    int ans=0;
    if(belong[L]==belong[R]){
        for(int i=L;i<=R;++i)
            if(arr[i]+mark[belong[L]]>=k)
                ++ans;
        return ans;
    }
    for(int i=L;i<=r[belong[L]];++i)
        if(arr[i]+mark[belong[L]]>=k)
            ++ans;
    for(int i=belong[L]+1;i<belong[R];++i)ans+=logalgor(i,k);
    for(int i=l[belong[R]];i<=R;++i)
        if(arr[i]+mark[belong[R]]>=k)
            ++ans;
    return ans;
}
int main(){
    char opt;
    int l,r,v;
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>arr[i];
    build();
    for(int i=1;i<=m;++i){
        cin>>opt>>l>>r>>v;
        if(opt=='M')modify(l,r,v);
        else cout<<find(l,r,v)<<endl;
    }
}