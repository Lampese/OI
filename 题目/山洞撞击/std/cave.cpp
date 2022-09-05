#include<cstdio>
#include<queue>
#include<cmath>
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
const int mn=10005,mm=10005,inf=2147483647;
struct node{
    double val;
    int num;
    bool operator <(const node &x)const{
        return val>x.val;
    }
};
int head[mn],ecnt=0,a[1005],b[1005],N,M,L,K,Scar,R;
double dis[mn];
priority_queue<node>q;
struct edge{
    int v;
    double w;
    int next;
}e[mm];
inline void add(int u,int v,double w){
   ++ecnt;
   e[ecnt].v=v;
   e[ecnt].w=w;
   e[ecnt].next=head[u];
   head[u]=ecnt;
}
bool bd(double a,double b){
    return fabs(a-b)>1e-6;
}
inline void dijkstra(int s){
    for(int i=1;i<=N+M+1;i++)dis[i]=1e6;
    node temp;
    temp.num=s;
    temp.val=0;
    dis[s]=0;
    q.push(temp);
    while(!q.empty()){
        node x=q.top();
        q.pop();
        int u=x.num;
        if(bd(x.val,dis[u]))continue;
        for(int i=head[u];i;i=e[i].next){
            int v=e[i].v;
            double w=e[i].w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                node y;
                y.num=v;
                y.val=dis[v];
                q.push(y);
            }
        }
    }
}
inline int A_In_B_Find(int x){
	int l=1,r=M,mid;
	while(l<=r){
	    mid=(l+r)>>1;
	    if(b[mid]<=x)l=mid+1;
	    else r=mid-1;
	}
	if(r==M)return -1;
    else return l;
}
inline int B_In_A_Find(int x){
	int l=1,r=N+1,mid;
	while(l<=r){
	    mid=(l+r)>>1;
	    if(a[mid]<=x)l=mid+1;
	    else r=mid-1;
	}
	if(r==N+1)return -1;
    else return l;
}
inline double Cost_S(int rs){
	return sqrt((rs)*(rs)+K*K);
}
inline double Cost_Theta(double rs){
	double theta=atan2(rs,0)-atan2(rs,K);
	if(theta>M_PI)theta-=2*M_PI;
	else if(theta<-M_PI)theta+=2*M_PI;
	theta=__builtin_fabs(theta*180.0/M_PI);
	return theta;
}
int main(){
	read(N);read(M);read(L);read(K);read(Scar);read(R);
	for(int i=1;i<=N;++i)read(a[i]);
	for(int i=1;i<=M;++i)read(b[i]);
	a[++N]=L;
	for(int i=1;i<=N-1;++i){
		int result=A_In_B_Find(a[i]);
        if(result==-1)continue;
		if(result<=M)add(i,result+N,Cost_S(b[result]-a[i])*Cost_Theta(b[result]-a[i]));
        if(result+1<=M)add(i,result+1+N,Cost_S(b[result+1]-a[i])*Cost_Theta(b[result+1-a[i]]));
	}
    for(int i=1;i<=M;++i){
		int result=B_In_A_Find(b[i]);
        if(result==-1)continue;
		if(result<=N)add(i+N,result,Cost_S(a[result]-b[i])*Cost_Theta(a[result]-b[i]));
        if(result+1<=N)add(i+N,result+1,Cost_S(a[result+1]-b[i])*Cost_Theta(a[result+1]-b[i]));
	}
    dijkstra(1);
    double V1=dis[N],V2=sqrt(2*R*Scar);
    printf("%.2lf\n",V1+V2);
	return 0;
}