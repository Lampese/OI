#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
long long arr[MAXN],sum[MAXN];
unsigned n,m,belong[MAXN],_size[MAXN],l[MAXN],r[MAXN];
bitset<MAXN>vis;
#define IN stdin->_IO_read_ptr<stdin->_IO_read_end?*stdin->_IO_read_ptr++:__uflow(stdin)
#define OUT(_ch) stdout->_IO_write_ptr<stdout->_IO_write_end?*stdout->_IO_write_ptr++=_ch:__overflow(stdout,_ch)
template<typename T>inline void read(T &x){
	x=0;
	char ch=IN;
	while(ch<47)ch=IN;
	while(ch>47)x=(x<<1)+(x<<3)+(ch^48),ch=IN;
}
template<typename T>void P(T x){
	if(-x>9)P(x/10);
	OUT(x%10+48);
}
inline long long query(int L,int R){
    long long ans(0);
    if(belong[L]==belong[R]){
        if(vis[belong[L]])return R-L+1;
        for(register int i=L;i<=R;++i)ans+=arr[i];
        return ans;
    }
    if(vis[belong[L]])ans+=r[belong[L]]-L+1;
    else for(register int i=L;i<=r[belong[L]];++i)ans+=arr[i];
    for(register int i=belong[L]+1;i<belong[R];++i)ans+=sum[i];
    if(vis[belong[R]])ans+=R-l[belong[R]]+1;
    else for(register int i=l[belong[R]];i<=R;++i)ans+=arr[i];
    return ans;
}
inline void modify(int L,int R){
    if(belong[L]==belong[R]){
        if(vis[belong[L]])return;
        for(register int i=L;i<=R;++i){
            if(arr[i]==1)continue;
            unsigned sqrted=__builtin_sqrt(arr[i]);
            sum[belong[L]]=sum[belong[L]]-arr[i]+sqrted;
            arr[i]=sqrted;
        }
        return;
    }
    if(!vis[belong[L]]){
        for(register int i=L;i<=r[belong[L]];++i){
            if(arr[i]==1)continue;
            unsigned sqrted=__builtin_sqrt(arr[i]);
            sum[belong[L]]=sum[belong[L]]-arr[i]+sqrted;
            arr[i]=sqrted;
        }
    }
    for(register int i=belong[L]+1;i<belong[R];++i){
        if(vis[i])continue;
        bool flag=true;
        sum[i]=0;
        for(register int j=l[i];j<=r[i];++j){
            if(arr[j]==1){
                ++sum[i];
                continue;
            }
            arr[j]=__builtin_sqrt(arr[j]);
            if(arr[j]!=1)flag=false;
            sum[i]+=arr[j];
        }
        if(flag)vis[i]=true;
    }
    if(!vis[belong[R]]){
        for(register int i=l[belong[R]];i<=R;++i){
            if(arr[i]==1)continue;
            unsigned sqrted=__builtin_sqrt(arr[i]);
            sum[belong[R]]=sum[belong[R]]-arr[i]+sqrted;
            arr[i]=sqrted;
        }
    }
}
int main(){
    int opt,L,R;
    read(n);
    for(register int i=1;i<=n;++i)read(arr[i]);
    int blocksize=__builtin_sqrt(n),cnt=n/blocksize;
    if(n%blocksize)++cnt;
    for(register int i=1,from=0,to=blocksize;i<cnt;++i){
        l[i]=from+1,r[i]=to,_size[i]=r[i]-l[i]+1;
        for(register int j=l[i];j<=r[i];++j){
            belong[j]=i;
            sum[i]+=arr[j];
            from+=blocksize;
            to+=blocksize;
        }
    }
    l[cnt]=blocksize*(cnt-1)+1,r[cnt]=n;
    for(register int j=l[cnt];j<=r[cnt];++j){
        belong[j]=cnt;
        sum[cnt]+=arr[j];
    }
    read(m);
    for(register int i=1;i<=m;++i){
        read(opt),read(L),read(R);
        if(L>R)swap(L,R);
        if(opt){
            P(query(L,R));
            OUT('\n');
        }else modify(L,R);
    }
}