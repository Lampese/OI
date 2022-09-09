#include<bits/stdc++.h>
#define MAXN 100005
#define IN stdin->_IO_read_ptr<stdin->_IO_read_end?*stdin->_IO_read_ptr++:__uflow(stdin)
#define OUT(_ch) stdout->_IO_write_ptr<stdout->_IO_write_end?*stdout->_IO_write_ptr++=_ch:__overflow(stdout,_ch)
using namespace std;
int n,m,ecnt,head[MAXN],in[MAXN],out[MAXN];
struct edge{
    int v,next;
}e[MAXN<<1];
inline void add(int u,int v){
    ++out[u],++in[v];
    e[++ecnt]={v,head[u]},head[u]=ecnt;
}
void P(__int128 x){if(x>9)P(x/10);OUT(x%10+48);}
inline __int128 gcd(__int128 x,__int128 y){return y==0?x:gcd(y,x%y);}
inline __int128 lcm(__int128 x,__int128 y){return x*y/gcd(x,y);}
struct frac{
    __int128 on=0,under=0;
    inline void dealwith(){
        __int128 c=gcd(on,under);
        on/=c,under/=c;
    }
    frac operator+(const frac x)const{
        if(x.on==0||x.under==0)return *this;
        if(on==0||under==0)return x;
        __int128 c=lcm(under,x.under);
        __int128 ac=c/under,bc=c/x.under;
        frac result={on*ac+x.on*bc,c};
        result.dealwith();
        return result;
    }
    frac operator/(const int x)const{
        frac result={on,under*x};
        result.dealwith();
        return result;
    }
}f[MAXN];
inline void toposort(){
    queue<int>q;
    for(register int i=1;i<=m;++i){
        q.push(i);
        f[i]={1,1};
    }
    while(!q.empty()){
        int u(q.front());
        q.pop();
        if(f[u].on==0||f[u].under==0)continue;
        frac val=f[u]/out[u];
        for(register int i=head[u];i;i=e[i].next){
            int v(e[i].v);
            f[v]=f[v]+val;
            if(--in[v]==0)q.push(v);
        }
    }
    for(register int i=m+1;i<=n;++i)
        if(out[i]==0){
            P(f[i].on);
            OUT(' ');
            P(f[i].under);
            OUT('\n');
        }
}
signed main(){
    int num,temp;
    cin>>n>>m;
    for(register int i=1;i<=n;++i){
        cin>>num;
        for(register int j=1;j<=num;++j){
            cin>>temp;
            add(i,temp);
        }
    }
    toposort();
}