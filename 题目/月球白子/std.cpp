#include<bits/stdc++.h>
#define MAXN 500005
using namespace std;
inline void read(int &x){
	x=0;
	char ch=getchar_unlocked();
	while(ch<47)ch=getchar_unlocked();		
	while(ch>47)x=(x<<1)+(x<<3)+(ch^48),ch=getchar_unlocked();
}
void print(int x){
	if(x>9)print(x/10);
	putchar_unlocked(x%10+48);
}
struct SunList{
    int l,r,v;
}SL[MAXN<<1];
int main(){
    int opt,l,r,v,pos,n,top(0);
    read(n);
    SL[++top]={1,n,0};
    for(register int i=1;i<=n;++i){
        read(opt);
        if(opt==1){
            read(l),read(r),read(v);
            SL[++top]={l,r,v};
        }else if(opt==2){
            read(pos);
            for(register int j=top;j;--j){
                if(SL[j].l<=pos&&SL[j].r>=pos){
                    print(SL[j].v);
                    putchar_unlocked('\n');
                    break;
                }
            }
        }else{
            read(pos);
            top-=pos;
        }
    }
}