#include<bits/stdc++.h>
using namespace std;
const long long P=1000000007;
long long ans=1,a[100005];
int main(){
    long long n,temp=10000000010;
    cin>>n;
    for(register int i=1;i<=n;++i){
        cin>>a[i];
        temp=min(temp,a[i]);
    }
    cout<<temp<<" ";
    for(register int i=1;i<=n;++i)ans=(ans*(a[i]/temp))%P;
    cout<<ans<<endl;
}