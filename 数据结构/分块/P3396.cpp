#include<bits/stdc++.h>
using namespace std;
#define MAXN 150005
int arr[MAXN],ans[390][390];
#define IN stdin->_IO_read_ptr<stdin->_IO_read_end?*stdin->_IO_read_ptr++:__uflow(stdin)
#define OUT(_ch) stdout->_IO_write_ptr<stdout->_IO_write_end?*stdout->_IO_write_ptr++=_ch:__overflow(stdout,_ch)
template<typename T>inline void read(T &x){
	x=0;
	char ch=IN;
	while(ch<47)ch=IN;
	while(ch>47)x=(x<<1)+(x<<3)+(ch&15),ch=IN;
}
inline void read_char(char &x){
    x=IN;
    while(x<65)x=IN;
}
template<typename T>void P(T x){
	if(x>9)P(x/10);
	OUT(x%10+48);
}
int main(){
    int n,m,_size,x,y;
    char opt;
    read(n),read(m);
    _size=min(n,10);
    for(register int i=1;i<=n;++i)read(arr[i]);
    for(register int i=1;i<=n;++i)
        for(register int p=1;p<=_size;++p)
            ans[p][i%p]+=arr[i];
    while(m--){
        read_char(opt),read(x),read(y);
        if(opt=='A'){
            if(x<=_size)P(ans[x][y]),OUT('\n');
            else{
                int a=0;
                for(register int j=y;j<=n;j+=x)a+=arr[j];
                P(a),OUT('\n');
            }
        }else{
            for(register int p=1;p<=_size;++p)ans[p][x%p]-=arr[x]-y;
            arr[x]=y;
        }
    }
}