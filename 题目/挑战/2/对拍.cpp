#include<bits/stdc++.h>
using namespace std;
inline void write(unsigned long long _num){
    if(_num>9)write(_num/10);
    putc(_num%10+'0',stdout);
}
inline unsigned long long fastpow(unsigned long long a,unsigned long long b,unsigned long long m){
	unsigned long long re=1,t=a;
	while(b){
		if(b&1)re=re*t%m; 
		t=t*t%m;
		b>>=1;
	}
	return re;
}
const unsigned long long m=137438953471;
#define inv(a,mod) fastpow(a,mod-2,mod)
unsigned long long l,r,p,sum;
int main(){
    cin>>l>>r>>p;
    for(register int i=l;i<=r;++i){
        sum+=inv(i,p);
        sum%=m;
    }
    cout<<sum;
}