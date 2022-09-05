#include<bits/stdc++.h>
using namespace std;
long long sum(int n){
    return n*(n+1)/2;
}
int main(){
    long long L,R,k,ans=0;
    cin>>L>>R;
    k=R;
    for(long long l=1,r;l<=R;l=r+1){
        if(k/l!=0)r=min(k/(k/l),R);
        else r=R;
        ans+=(sum(r)-sum(l-1))*(k/l);
    }
    k=L-1;
    for(long long l=1,r;l<=R;l=r+1){
        if(k/l!=0)r=min(k/(k/l),R);
        else r=R;
        ans-=(sum(r)-sum(l-1))*(k/l);
    }
    cout<<ans;
}