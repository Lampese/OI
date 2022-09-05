#include<bits/stdc++.h>
using namespace std;
unsigned long long l,r,p,sum,opt;
unsigned long long inv[10000005];
const unsigned long long m=137438953471;
unsigned long long Inv(unsigned long long x){
    if(x<10000000)return inv[x];
    else return (unsigned long long)(p-p/x)*Inv(p%x)%p;
}
int main(){
    cin>>opt;
    scanf("%lld%lld%lld",&l,&r,&p);
    inv[1]=1;
    for(register int i=2;i<10000000;++i)
        inv[i]=(unsigned long long)(p-p/i)*inv[p%i]%p;
    for(register int i=l;i<=r;++i){
        sum+=Inv(i);
        if(sum>=m)sum-=m;
    }
    cout<<sum;
}