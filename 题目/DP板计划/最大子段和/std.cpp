#include<bits/stdc++.h>
#define Max(a,b) a<b?b:a
using namespace std;
inline void read(int &x){
	x=0;
    int w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
        if(ch=='-')w=-1;
        ch=getchar();
    }
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
    x*=w;
}
int n,temp,dp,ans=-2147483647;
int main(){
    read(n);read(dp);
    for(register int i=2;i<=n;++i){
        read(temp);
        dp=Max(dp+temp,temp);
        if(dp>ans)ans=dp;
    }
    printf("%d",ans);
}