#include<bits/stdc++.h>
#define MAXN 1000005
#define read_fs
#define out_fs
using namespace std;
#define IN stdin->_IO_read_ptr<stdin->_IO_read_end?*stdin->_IO_read_ptr++:__uflow(stdin)
#define OUT(_ch) stdout->_IO_write_ptr<stdout->_IO_write_end?*stdout->_IO_write_ptr++=_ch:__overflow(stdout,_ch)
const __int128 P=998244353;
__int128 n,k,p,ans,a[MAXN],suma[MAXN],sumb[MAXN];
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
#ifdef out_fs
    template<typename T>void print(T x){if(x<0)OUT('-'),__print(-x);else __print(x);}
    template<typename T>void printspace(T x){print(x),OUT(' ');}
    template<typename T>void println(T x){print(x);OUT('\n');}
#else
    template<typename T>void print(T x){__print(x);}
    template<typename T>void printspace(T x){__print(x),OUT(' ');}
    template<typename T>void println(T x){__print(x),OUT('\n');}
#endif
int main(){
    read(n),read(k);
    for(register __int128 i=1;i<=n;++i){
        read(a[i]);
        if(a[i]<0)p=i;
        suma[i]=(suma[i-1]+a[i]+P)%P;
        sumb[i]=(sumb[i-1]+a[i]*a[i]+P)%P;
    }
    for(register __int128 i=1;i<=k;++i){
        while(((-(a[p]+1))<(a[p]+i))&&(p>0))--p;
        ans=(ans+((sumb[n]-sumb[p])+2*i*(suma[n]-suma[p])+(n-p)*(i*i)%P+P)%P
                +(sumb[p]+2*suma[p]+p+P)%P+P)%P;
    }
    println(ans);
}