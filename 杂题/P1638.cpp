#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005];
int main(){
    int n,m,aa,bb,l=1,r=1,k=1,ans=2147483647;
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    b[a[1]]=1;
    while(l<=r&&r<=n){
        if(k==m){
            if(r-l+1<ans){
                ans=r-l+1;
                aa=l,bb=r;
            }
            if(b[a[l]]==1)--k;
            --b[a[l]];
            ++l;
        }else{
            ++r;
            if(b[a[r]]==0)++k;
            ++b[a[r]];
        }
    }
    cout<<aa<<" "<<bb<<endl;
}