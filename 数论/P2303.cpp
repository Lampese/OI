#include<bits/stdc++.h>
using namespace std;
long long eular(long long n){
    long long ans=n;
    for(long long i=2;i*i<=n;++i){
        if(n%i==0){
            ans=ans/i*(i-1);
            while(n%i==0)n/=i;
        }
    }
    if(n>1)ans=ans/n*(n-1);
    return ans;
}
int main(){
    long long n,ans=0;
    cin>>n;
    for(register long long i=1;i*i<=n;++i)
        if(n%i==0)
            if(i*i==n)ans+=i*eular(n/i);
            else ans+=i*eular(n/i)+(n/i)*eular(i);
    cout<<ans;
    return 0;
}