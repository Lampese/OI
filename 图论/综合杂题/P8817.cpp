#include<bits/stdc++.h>
#define int long long
#define MAXN 2505
using namespace std;
#define IN stdin->_IO_read_ptr<stdin->_IO_read_end?*stdin->_IO_read_ptr++:__uflow(stdin)
#define OUT(_ch) stdout->_IO_write_ptr<stdout->_IO_write_end?*stdout->_IO_write_ptr++=_ch:__overflow(stdout,_ch)
template<typename T>inline void read(T &x){
	x=0;
    #ifdef read_fs
    int w(1);
    #endif
	char ch=IN;
	while(ch<47){
        #ifdef read_fs
        if(ch=='-')w=-1;
        #endif
        ch=IN;
    }
	while(ch>47)x=(x<<1)+(x<<3)+(ch&15),ch=IN;
    #ifdef read_fs
    if(w<0)x=-x;
    #endif
}
template<typename T>void __print(T x){if(x>9)__print(x/10);OUT(x%10+48);}
#ifdef out_fs
    template<typename T>void print(T x){if(x<0)OUT('-'),__print(-x);else __print(x);}
    template<typename T>void printspace(T x){print(x),OUT(' ');}
    template<typename T>void println(T x){print(x);OUT('\n');}
#else
    template<typename T>void print(T x){__print(x);}
    template<typename T>void printspace(T x){__print(x),OUT(' ');}
    template<typename T>void println(T x){__print(x),OUT('\n');}
#endif
int n,m,k,ecnt,head[MAXN],p[MAXN],dis[MAXN][MAXN],dp[MAXN][6];
vector<int>cango[MAXN];
bitset<MAXN>vis;
struct edge{
    int v,next;
}e[30000];
inline void add(int u,int v){
    e[++ecnt]={v,head[u]};
    head[u]=ecnt;
}
inline void bfs(int s){
    bitset<MAXN>vv;
    queue<int>q;
    q.push(s);
    dis[s][s]=0;
    while(!q.empty()){
        int u(q.front());
        q.pop();
        if(vv[u])continue;
        vv[u]=1; 
        for(register int i=head[u];i;i=e[i].next){
            int v(e[i].v);
            if(dis[s][v]>dis[s][u]+1){
                dis[s][v]=dis[s][u]+1;
                q.push(v);
            }
        }
    }
}
void dfs(int x,int step,int w){
    if(step==4){
        if((dis[x][1]-1)<=k)dp[1][5]=max(dp[1][5],w);
        return;
    }
    if(w<dp[x][step])return;
    else dp[x][step]=w;
    vis[x]=1;
    for(int to:cango[x])
        if(!vis[to])
            dfs(to,step+1,w+p[to]);
    vis[x]=0;
}
signed main(){
    cin>>n>>m>>k;
    for(register int i=2;i<=n;++i)read(p[i]);
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=n;++j)
            dis[i][j]=1000000000;
    for(register int i=1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    for(register int i=1;i<=n;++i)bfs(i);
    for(register int i=1;i<=n;++i)
        for(register int j=2;j<=n;++j)
            if(i!=j)
                if((dis[i][j]-1)<=k)
                    cango[i].push_back(j);
    dfs(1,0,0);
    __print(dp[1][5]);
}