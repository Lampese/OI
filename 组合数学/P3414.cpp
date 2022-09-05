#include<bits/stdc++.h>
using namespace std;
const long long P=6662333;
inline long long fastpow(long long a,long long p){
    long long ans=1;
    while(p){
        if(p&1)ans=(ans*a)%P;
        a=(a*a)%P;
        p>>=1;
    }
    return ans%P;
}
int main(){
    long long n;
    cin>>n;
    cout<<fastpow(2,n-1)%P<<endl;
}