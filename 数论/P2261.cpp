#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,k,r,ans=0;
    cin>>n>>k;
    ans+=n*k;
    for(long long l=1,r;l<=n;l=r+1){
        if(k/l!=0)r=min(k/(k/l),n);
        else r=n;
        ans-=(k/l)*(r-l+1)*(l+r)/2;
    }
    cout<<ans;
}