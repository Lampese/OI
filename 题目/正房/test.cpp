#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans=0;
    cin>>n;
    for(register int a=1;a<=n;++a)
        for(register int b=1;b<=n/a;++b)
            for(register int c=1;c<=n/(a*b);++c)
                for(register int d=1;d<=n/(a*b*c);++d)
                    if(a*b*c*d<=n)++ans;
    cout<<ans<<endl;
}