#include<bits/stdc++.h>
using namespace std;
const unsigned long long mod=998244353;
bitset<5000005>vis;
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
    unsigned long long m,ans=1;
    cin>>m;
    for(register int i=2;i<=m;++i){
        if(vis[i])continue;
        if(m%i==0){
            for(register int j=2,k;(k=j*i)<=m;++j)vis[k]=1;
            continue;
        }
        ans+=fastpow(i,m);
        if(ans>mod)ans-=mod;
    }
    cout<<ans<<endl;
}