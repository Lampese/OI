#include<bits/stdc++.h>
using namespace std;
const int N=100005;
const int M=200005;
const int inf=0x7fffffff;
int head[N],n,m,s,dis[N],cnt;
struct edge{
	int next,to,val;
}e[M];
struct node{
	int num,dis;
	bool operator <(const node &x)const{
		return x.dis<dis;
	}
};
void add(int u,int v,int d){
	e[++cnt]={head[u],v,d};
	head[u]=cnt;
}
priority_queue<node>q;
void dij(){
	for(int i=1;i<=n;i++)
	dis[i]=inf;
	dis[s]=0;
	q.push({s,0});
	while(!q.empty()){
		node x=q.top();
		q.pop();
		int u=x.num;
		if(dis[u]!=x.dis)
		continue;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to,w=e[i].val;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
}
int main(){
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
	}
	dij();
	for(int i=1;i<=n;i++)
	cout<<dis[i]<<" ";
}
