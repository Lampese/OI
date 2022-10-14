#include<bits/stdc++.h>
#define MAXN 55
using namespace std;
int n,f[MAXN][MAXN];
string s;
int main(){
    cin>>s;
    n=s.size();
    s=" "+s;
    memset(f,0x7f,sizeof f);
    for(register int i=1;i<=n;++i)f[i][i]=1;
    for(register int l=2;l<=n;++l)
        for(register int i=1;i+l-1<=n;++i){
            int j=i+l-1;
            if(s[i]==s[j])f[i][j]=min(f[i+1][j],f[i][j-1]);
            else{
                for(register int k=i;k<j;++k)
                    f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
            }
        }
    cout<<f[1][n]<<endl;
}