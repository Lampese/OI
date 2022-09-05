#include<bits/stdc++.h>
#define IN stdin->_IO_read_ptr<stdin->_IO_read_end?*stdin->_IO_read_ptr++:__uflow(stdin)
#define OUT(_ch) stdout->_IO_write_ptr<stdout->_IO_write_end?*stdout->_IO_write_ptr++=_ch:__overflow(stdout,_ch)
inline __attribute__((always_inline)) void read(register unsigned &x){
	x=0;
	static char ch;
	while((ch=IN)>47)x=(x<<1)+(x<<3)+(ch^48);
}
int main(){
    register struct _{unsigned key,next;}e[120000];
    register unsigned N,k,head[65536],ecnt,i;
    register bool b;
    read(N);
    while(N--){
        b=((IN)=='1');IN;read(k);
        if(b)i=k&65535,e[++ecnt]={k,head[i]},head[i]=ecnt;
        else{
            for(i=head[k&65535];i;i=e[i].next)
				if(k==e[i].key){
                    OUT('1');
					break;
				}
            if(!i)OUT('0');
        }
    }
}