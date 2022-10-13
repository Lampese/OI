#include<bits/stdc++.h>
#define MAXN 15
using namespace std;
int s,n,d,a[MAXN],b[MAXN],f[10000005];
int main(){
    cin>>s>>n>>d;
    for(register int i=1;i<=d;++i)cin>>a[i]>>b[i];
    for(register int y=1;y<=n;++y){
        for(register int i=1;i<=d;++i)
            for(register int j=a[i];j<=s;++j)
                f[j]=max(f[j],f[j-a[i]]+b[i]);
        s+=f[s];
    }
    cout<<s<<endl;
}