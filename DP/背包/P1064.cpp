#include<bits/stdc++.h>
using namespace std;
#define Max(a,b) a>b?a:b
#define IN stdin->_IO_read_ptr<stdin->_IO_read_end?*stdin->_IO_read_ptr++:__uflow(stdin)
#define OUT(_ch) stdout->_IO_write_ptr<stdout->_IO_write_end?*stdout->_IO_write_ptr++=_ch:__overflow(stdout,_ch)
template<typename T>inline void read(T &x){
	x=0;
	char ch=IN;
	while(ch<47)ch=IN;
	while(ch>47)x=(x<<1)+(x<<3)+(ch&15),ch=IN;
}
template<typename T>void __print(T x){if(x>9)__print(x/10);OUT(x%10+48);}
int n,m,cnt,V,P,Q;
int v[100][3],w[100][3],_cnt[100],_map[100],f[40000];
int main(){
    read(n),read(m);
    n/=10;
    for(register int i=1;i<=m;++i){
        read(V),read(P),read(Q);
        V/=10;
        P*=V;
        if(Q==0){
            ++cnt;
            v[cnt][0]=V;
            w[cnt][0]=P;
            _map[i]=cnt;
        }else{
            Q=_map[Q];
            ++_cnt[Q];
            v[Q][_cnt[Q]]=V;
            w[Q][_cnt[Q]]=P;
        }
    }
    for(register int i=1;i<=cnt;++i)
        for(register int j=n;j>=v[i][0];--j){
            f[j]=Max(f[j],f[j-v[i][0]]+w[i][0]);
            if(j>=v[i][0]+v[i][1])f[j]=Max(f[j],f[j-v[i][0]-v[i][1]]+w[i][0]+w[i][1]);
            if(j>=v[i][0]+v[i][2])f[j]=Max(f[j],f[j-v[i][0]-v[i][2]]+w[i][0]+w[i][2]);
            if(j>=v[i][0]+v[i][1]+v[i][2])f[j]=Max(f[j],f[j-v[i][0]-v[i][1]-v[i][2]]+w[i][0]+w[i][1]+w[i][2]);
        }
    __print(f[n]*10);
}