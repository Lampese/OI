#include<bits/stdc++.h>
using namespace std;
int main(){
    unsigned n,ab,ans=0;
    cin>>n;
    for(register unsigned a=1;a<=n;++a)
        for(register unsigned b=1,end=n/a;b<=end;++b){
            ab=n/(a*b);
            for(unsigned l=1,r;l<=ab;l=r+1){
                unsigned temp=(ab/l);
                r=ab/temp; 
                ans+=(r-l+1)*temp;
            }
        }
    cout<<ans<<endl;
}