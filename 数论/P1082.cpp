#include<bits/stdc++.h>
using namespace std;
void exgcd(long long a,long long b,long long &x,long long &y){
	if(!b){x=1,y=0;return;}
	exgcd(b,a%b,x,y);
	long long temp=x;x=y;y=temp-(a/b)*y;
}
inline int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
bool solve(long long a,long long b,long long c,long long &x,long long &y){
	long long d=gcd(a,b);
	if(c%d)return false;
	exgcd(a,b,x,y);
	long long k=c/d;
	x*=k,y*=k;
	return true;
}
signed main(){
    long long a,b,x,y;
    cin>>a>>b;
    solve(a,b,1,x,y);
    x=(x%b+b)%b;
    cout<<x<<endl;
}