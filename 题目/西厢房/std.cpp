#include<bits/stdc++.h>
using namespace std;
const long long P=998244353;
long long fastpow(long long a,long long b){
	long long ans=1;
	while(b){
		if(b&1)ans=ans*a%P; 
		a=a*a%P;
		b>>=1;
	}
	return ans;
}
i   nt main(){
    long long n,m,ans=0;
    cin>>n>>m;
    for(register int i=1;i<=m;++i)ans=(ans+fastpow(i,n-1))%P;
    cout<<(ans*n)%P<<endl;
}