#include<bits/stdc++.h>
using namespace std;
const __int128 mod=998244353; 
int main(){
    unsigned long long m;
    __int128 ans=1;
    cin>>m;
    for(int i=2,e=sqrt(m);i<=e;++i)
        if(m%i==0)ans=ans*m%mod;
    cout<<(unsigned long long)(ans)<<endl;
}