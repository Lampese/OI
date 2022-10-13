#include<bits/stdc++.h>
const unsigned long long mod=998244353;
using namespace std;
unsigned long long fastpow(unsigned long long a,unsigned long long b){
	unsigned long long re=1;
	while(b){
		if(b&1)re=re*a%mod; 
		a=a*a%mod;
		b>>=1;
	}
	return re;
}
int main(){
    unsigned long long m,cnt(0);
    cin>>m;
    for(int i=2,e=sqrt(m);i<=e;++i)
        if(m%i==0)++cnt;
    cout<<fastpow(m,cnt);
}