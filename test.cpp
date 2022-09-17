#include<bits/stdc++.h>
using namespace std;
inline string summon(int x){
    string result="\n";
    while(x--)result.push_back(' ');
    return result;
}
int main(){
    int n,j;
    cin>>n;
    for(register int i=1;i<=n;++i){
        cout<<summon(n-i);
        for(j=1;j<=i;++j)cout<<j;
        for(j-=2;j>=1;--j)cout<<j;
    }
    for(register int i=n-1;i>=1;--i){
        cout<<summon(n-i);
        for(j=1;j<=i;++j)cout<<j;
        for(j-=2;j>=1;--j)cout<<j;
    }
}