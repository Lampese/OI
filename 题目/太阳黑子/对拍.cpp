#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("Sun1.in","r",stdin);
    freopen("Sun1a.out","w",stdout);
    int n,opt,l,r,v;
    cin>>n;
    while(n--){
        cin>>opt>>l>>r;
        if(opt==1){
            cin>>v;
            for(register int i=l;i<=r;++i)
                a[i]=v;
        }else if(opt==2){
            int ans=0;
            for(register int i=l;i<=r;++i)
                ans+=a[i];
            cout<<ans<<endl;
        }
        else if(opt==3)sort(a+1+l,a+1+r);
        else{
            cin>>v; 
            for(register int i=l;i<=r;++i)
                a[i]+=v;
        }
    }
}