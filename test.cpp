#include<bits/stdc++.h>
using namespace std;
const unsigned long long P=998244353;
unsigned long long jc(unsigned long long x){
    unsigned long long ans=1;
    for(register unsigned long long i=1;i<=x;++i)ans=(ans*i)%P;
    return ans%P;
}
int main(){
    unsigned long long n,m,ans=0;
    cin>>n>>m;
    for(register unsigned long long i=1;i<=m;++i){
        for(register unsigned long long j=1;j<=n;++j){
            ans+=(j*(((unsigned long long)pow(i-1,n-j))%P)*jc(n)%P/jc(n-j)%P/jc(j)%P)%P;
        }
    }
    cout<<ans<<endl;
}