#include<bits/stdc++.h>
using namespace std;
inline void read(long long &x){
	x=0;
	char ch=getchar_unlocked();
	while(ch<47)ch=getchar_unlocked();		
	while(ch>47)x=(x<<1)+(x<<3)+(ch^48),ch=getchar_unlocked();
}
inline long long fastpow(long long a,long long b,long long m){
	long long re=1,t=a;
	while(b){
		if(b&1)re=re*t%m; 
		t=t*t%m;
		b>>=1;
	}
	return re;
}
int main(){
    long long tmp,n,p,k,nowleft(0),nowunder(1);
    read(n),read(p),read(k);
    for(register long long i=1,c=k%p;i<=n;++i,c=c*k%p){
        read(tmp);
        nowleft=nowleft*tmp%p+nowunder*c%p;
        nowunder=nowunder*tmp%p;
    }
    cout<<nowleft*fastpow(nowunder,p-2,p)%p;
}