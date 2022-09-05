#include<bits/stdc++.h> 
using namespace std;
long long exgcd(long long a,long long b,long long &x,long long &y){
	if(!b){x=1,y=0;return a;}
	long long gcd=exgcd(b,a%b,x,y);
	long long temp=x;x=y;y=temp-(a/b)*y;
	return gcd;
}
bool solve(long long a,long long b,long long c,long long &x,long long &y,long long &d){
	d=exgcd(a,b,x,y);
	if(c%d)return false;
	long long k=c/d;
	x*=k,y*=k;
	return true;
}
signed main(){
    long long T;
    cin>>T;
    while(T--){
        long long a,b,c,x,y,d;
        cin>>a>>b>>c;
        if(!solve(a,b,c,x,y,d)){
            cout<<"-1"<<endl;
            continue;
        }
        a/=d,b/=d;
        x=(x%b+b)%b;
        if(x==0)x=b;
        y=(c-a*x)/b;
        if(y>0){
            long long xmax,xmin,ymax,ymin;
            xmin=x,ymax=y;
            y%=a;   
            if(y==0)y=a;
            x=(c-b*y)/a;
            xmax=x,ymin=y;
            cout<<(xmax-xmin)/b+1<<" "<<xmin<<" "<<ymin<<" "<<xmax<<" "<<ymax<<endl;
        }else{
            long long xmin=x,ymin=y%a+a;
            cout<<xmin<<" "<<ymin<<endl;
        }
    }
}