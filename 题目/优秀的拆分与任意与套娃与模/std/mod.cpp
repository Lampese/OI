#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
inline void read(int &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
}
#define Rep(i,a,b) for(int i=a;i<=b;i++)
#define _Rep(i,a,b) for(int i=a;i>=b;i--)
const int N=1e7+3;
int phis[N],p,bl,poww[N][2];
inline int phi(int x){
    if(phis[x]!=0)return phis[x];
    int res=x;
    for(int i=2;i*i<=x;i++){
        if(x%i==0)res=res/i*(i-1);
        while(x%i==0)x/=i;
    }
    if(x>1)res=res/x*(x-1);
    phis[x]=res;
    return res;
}
inline int Qpow(int ind){
    ind%=phi(p);
    return 1ll*poww[ind%bl][0]*poww[ind/bl][1]%p;
}
inline void Pre(int a){
    bl=sqrt(p)+1;
    poww[0][0]=1;
    Rep(i,1,bl)poww[i][0]=1ll*poww[i-1][0]*a%p;
    poww[0][1]=1;
    Rep(i,1,bl)poww[i][1]=1ll*poww[i-1][1]*poww[bl][0]%p;
}
inline int _gcd(int x,int y){
    while(y^=x^=y^=x%=y);
	return x;
}
inline int _lcm(int a,int b){
    return a*b/_gcd(a,b);
}
int k[4000005];
int main(){
    int a,b,q;
    read(a);read(b);read(q);read(p);
    for(register int i=1;i<=q;++i)read(k[i]);
    int n=_lcm(a,b);
    int sum=0;
    for(register int j=1;j<=n;++j){
        Pre(j);
        for(register int i=1;i<=q;++i){
            sum+=Qpow(k[i]);
            sum%=p;
        }
    }
    cout<<sum<<endl;
}