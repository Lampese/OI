#include<bits/stdc++.h>
using namespace std;
int f[2005][2005],opt;
int main(){
    cin>>opt;
	string a,b;
	cin>>a>>b;
	for(register int i=1;i<=a.size();++i)f[i][0]=i;
	for(register int i=1;i<=b.size();++i)f[0][i]=i;
	for(register int i=1;i<=a.size();++i)
		for(register int j=1;j<=b.size();++j)
			f[i][j]=min(min(f[i-1][j]+1,f[i][j-1]+1),f[i-1][j-1]+(a[i-1]!=b[j-1]));
	cout<<f[a.size()][b.size()];
}