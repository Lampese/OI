#include<bits/stdc++.h>
#define MAXN 200005
#define int long long
using namespace std;
namespace OldG{
    int head[MAXN],ecnt=0;
    struct edge{int v,next;}e[MAXN];
    inline void add(int u,int v){
        e[++ecnt]={v,head[u]};
        head[u]=ecnt;
    }
}
int head[MAXN],v[MAXN],_next[MAXN],f[MAXN],p[MAXN],in[MAXN],ecnt,n,m,cnt,k;
bitset<MAXN>vis,dfn,cango;
inline void add(int u,int to){
    v[++ecnt]=to;
    _next[ecnt]=head[u];
    head[u]=ecnt;
    ++in[to];
}
inline void init(){
    vis.reset(),dfn.reset(),cango.reset();
    ecnt=cnt=0;
    for(register int i=1;i<=n;++i)f[i]=1;
    memset(head,0,sizeof(head));
    memset(v,0,sizeof(v));
    memset(_next,0,sizeof(_next));
    memset(in,0,sizeof(in));
}
inline bool dfs(int u){
    vis[u]=dfn[u]=1;
    for(register int i=head[u];i;i=_next[i]){
        if(vis[v[i]])return 1;
        if(!dfn[v[i]])
            if(dfs(v[i]))
                return 1;
    }
    return vis[u]=0;
}
inline bool check(int mid){
    init();
    for(register int i=1;i<=n;++i)
        if(p[i]<=mid){
            ++cnt;
            cango[i]=1;
            for(register int j=OldG::head[i];j;j=OldG::e[j].next){
                int to(OldG::e[j].v);
                if(p[to]<=mid)add(i,to);
            }
        }
    for(register int i=1;i<=n;++i)
        if(cango[i]&&(!dfn[i]))
            if(dfs(i))return 1;
    if(k>cnt)return 0;
    queue<int>q;
    for(register int i=1;i<=n;++i)
        if(cango[i]&&in[i]==0)q.push(i);
    while(!q.empty()){
        int u(q.front());
        q.pop();
        for(register int i=head[u];i;i=_next[i]){
            int to(v[i]);
            f[to]=max(f[to],f[u]+1);
            if(f[to]>=k)return 1;
            if(--in[to]==0)q.push(to);
        }
    }
    return 0;
}
signed main(){
    int u,v,l(1),r=1e9,ans(0);
    cin>>n>>m>>k;
    for(register int i=1;i<=n;++i)cin>>p[i];
    for(register int i=1;i<=m;++i){
        cin>>u>>v;
        OldG::add(u,v);
    }
    if(m==0){
		if(k>1){
			cout<<-1;
			return 0;
		}
        ans=1e9;
		for(int i=1;i<=n;++i)ans=min(ans,p[i]);
		cout<<ans;
		return 0;
	}
    while(l<r){
        int mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            r=mid;
        }else l=mid+1;
    }
    if(ans==0)cout<<-1<<endl;
    else cout<<ans<<endl;
}