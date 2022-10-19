//Lampese Defult 2022/9/7
#include<bits/stdc++.h>
using namespace std;
#define IO_unlock
#define read_fs
#define out_fs
#define fi first
#define se second
typedef long long ll;
inline bool upper(int &a,int &b){return a<b;}
inline bool under(int &a,int &b){return a>b;}
#define For(i,l,r) for(register int i=l;i<=r;++i)
#define whileto(n) while(n--)
#ifdef IO_unlock
#define IN stdin->_IO_read_ptr<stdin->_IO_read_end?*stdin->_IO_read_ptr++:__uflow(stdin)
#define OUT(_ch) stdout->_IO_write_ptr<stdout->_IO_write_end?*stdout->_IO_write_ptr++=_ch:__overflow(stdout,_ch)
#else
#define IN getchar()
#define OUT(_ch) putchar(_ch)
#endif
template<typename T>inline T mul(T x,T y,const T p){
	register T res(0);
	for(;y;y>>=1,x=(x+x)%p)if(y&1)res=(res+x)%p;
	return res;
}
template<typename T>inline void mod(T &x,const T P){x=x>P?x-P:x;}
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
    template<typename T>inline void ip(T &x){if(x<0)OUT('-'),print(-x);}
    template<typename T>void print(T x){ip(x),print(x);}
    template<typename T>void printspace(T x){print(x),OUT(' ');}
    template<typename T>void println(T x){print(x);OUT('\n');}
#else
    template<typename T>void print(T x){__print(x);}
    template<typename T>void printspace(T x){__print(x),OUT(' ');}
    template<typename T>void println(T x){__print(x),OUT('\n');}
#endif
signed main(){

}