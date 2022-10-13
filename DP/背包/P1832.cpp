#include<bits/stdc++.h>
using namespace std;
inline bool isprime(int n){
    if(n==2)return true;
    for(register int i=2;i<n;++i)
        if(n%i==0)return false;
    return true;
}
long long n,dp[10005];
int main(){
    cin>>n;
    dp[0]=1;
    for(register int i=2;i<=n;++i)
        if(isprime(i))
            for(register int j=i;j<=n;++j)
                dp[j]+=dp[j-i];
    cout<<dp[n]<<endl;
}