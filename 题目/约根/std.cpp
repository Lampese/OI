#include<bits/stdc++.h>
using namespace std;
inline void read(long &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
}
inline long fastpow(long a,long b){
	long re=1,t=a;
	while(b){
		if(b&1)re=re*t;
		t=t*t;
		b>>=1;
	}
	return re;
}
void write(long x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int main(){
	long T,n,m,p,q;
    read(T);
    for(register long i=1;i<=T;++i){
        read(n),read(m);
        p=pow(n,1.0/(double)m);
        for(;p>0;--p){
			if(p==1)q=1;
			else q=fastpow(p,m);
            if(n%p==0&&n%q==0){
				write(p),putchar(' ');
				write(n/q),putchar('\n');
                break;
            }
		}
    }
}