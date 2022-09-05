#include<bits/stdc++.h>
using namespace std;
const int P=1000000007;
int n,temp,b[5005];
long long ans=0;
long long C(long long x){ 
    return (x*(x-1)/2)%P;
}
int main(){
    cin>>n;
    while(n--){
        cin>>temp;
        ++b[temp];
    }
    for(register int i=1;i<=temp;++i){
        if(b[i]<2)continue;
        long long t(0);
        for(register int j=1;j<=(i>>1);++j){
            if(b[j]==0||b[i-j]==0)continue;
            if(j!=(i-j))t=(t+b[j]*b[i-j])%P;
            else if(b[j]>=2)t=(t+C(b[j]))%P;
        }
        ans=(ans+C(b[i])*t)%P;
    }
    cout<<ans<<endl;
}