#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
#define IN getchar()
template<typename T>inline void read(T &x){
	x=0;
	char ch=IN;
	while(ch<47)ch=IN;
	while(ch>47)x=(x<<1)+(x<<3)+(ch^48),ch=IN;
}
int fa[MAXN],cnt[MAXN];
int n,m,q;
vector<pair<int,int>>e[MAXN],que,ques;
map<pair<int,int>,int>ans;
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
inline void marge(int x,int y){
    x=find(x),y=find(y);
    if(x!=y)fa[x]=y;
}
inline void init(){
    for(register int i=1;i<=n;++i)
        fa[i]=i;
}
inline void deal_a(int color){
    init();
    for(auto v:e[color])marge(v.first,v.second);
    for(auto v:que){
        int fx=find(v.first),fy=find(v.second);
        if(fx==fy)++ans[v];
    }
}
inline void deal_b(int color){
    int p[MAXN],tot(0);
    init();
    for(auto v:e[color]){
        p[++tot]=v.first,p[++tot]=v.second;
        marge(v.first,v.second);
    }
    sort(p+1,p+tot+1);
    tot=unique(p+1,p+tot+1)-p-1;
    for(register int i=1;i<=tot;++i)
        for(register int j=i+1;j<=tot;++j){
            int u=p[i],v=p[j];
            u=find(u),v=find(v);
            if(u==v&&ans.count({p[i],p[j]}))
                ++ans[{p[i],p[j]}];
        }
}
int main(){
    int u,v,c;
    read(n),read(m);
    for(register int i=1;i<=m;++i){
        read(u),read(v),read(c);
        ++cnt[c];
        e[c].push_back({min(u,v),max(u,v)});
    }
    read(q);
    while(q--){
        read(u),read(v);
        ques.push_back({min(u,v),max(u,v)});
        if(!ans.count({min(u,v),max(u,v)})){
            que.push_back({min(u,v),max(u,v)});
            ans[{min(u,v),max(u,v)}]=0;            
        }
    }
    for(register int i=1;i<=m;++i)
        if(cnt[i]){
            if(cnt[i]<=sqrt(m))deal_b(i);
            else deal_a(i);
        }
    for(auto v:ques)cout<<ans[v]<<endl;
}