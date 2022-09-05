#include<stdio.h>
int k[3500005];
int mod[10000007];
inline void read(int &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
}
int main(){
    int q,m,n;
    read(q);read(m);read(n);
    mod[0]=1;
    for(int i = 1; i < 10000007; i++)
        mod[i] = (n*mod[i-1])%m;
    for(int i = 0 ; i<q ; i++)
        read(k[i]);
    int cnt  = 0 ;
    for(int i = 0; i <q ; i++)
        cnt=(cnt+mod[k[i]])%m;
    printf("%d",cnt);
    return 0;
}
