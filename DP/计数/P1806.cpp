#include<bits/stdc++.h>
#define MAXN 505
using namespace std;
long long n,f[MAXN];
int main(){
    cin>>n;
    f[0]=1;
    for(register int i=1;i<=500;++i)
        for(register int j=n;j>=i;--j)
            f[j]+=f[j-i];
    cout<<f[n]-1<<endl;
}