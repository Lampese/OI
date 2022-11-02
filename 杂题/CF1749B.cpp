#include<bits/stdc++.h>
#define int long long
using namespace std;
#define MAXN 200005
int t,n,a[MAXN],b[MAXN];
signed main(){
    cin>>t;
    while(t--){
        cin>>n;
        int left=1,right=n,ans(0);
        for(register int i=1;i<=n;++i)cin>>a[i];
        for(register int i=1;i<=n;++i)cin>>b[i];
        while(left!=right){
            if(b[left]<b[right]){
                ans+=a[left];
                a[left+1]+=b[left];
                ++left;
            }else{
                ans+=a[right];
                a[right-1]+=b[right];
                --right;
            }
        }
        ans+=a[left];
        cout<<ans<<endl;
    }
}