#include<bits/stdc++.h>
#define MAXN 15
#define MAXM 1005
#define urd uniform_real_distribution
using namespace std;
const double D=0.95;
int n,m,result=0;
double r,ansx=0,ansy=0;
struct building{
    double x,y,r;
}b[MAXN];
struct enemy{
    double x,y;
}e[MAXM];
inline double distance(double x,double y,double X,double Y){
    return sqrt((x-X)*(x-X)+(y-Y)*(y-Y));
}
inline double calc(double x,double y){
    int ans(0);
    double R=r;
    for(register int i=1;i<=n;++i){
        double dis=distance(x,y,b[i].x,b[i].y);
        if(dis<b[i].r)return 0;
        R=min(R,dis-b[i].r);
    }
    for(register int i=1;i<=m;++i)
        if(distance(x,y,e[i].x,e[i].y)<=R)
            ++ans;
    return ans;
}
inline void out_fire(){
    double T=3144;
    double x=ansx,y=ansy;
    while(T>1e-15){
        double X=x+((rand()<<1)-RAND_MAX)*T;
        double Y=y+((rand()<<1)-RAND_MAX)*T;
        double now=calc(X,Y);
        double delta=now-result;
        if(delta>0){
            ansx=X;
            ansy=Y;
            result=now;
        }else if(exp(delta/T)*RAND_MAX>rand()){
            ansx=X;
            ansy=Y;
        }
        T*=D;
    }
}
inline void doit(){
    ansx/=(m*1.0),ansy/=(m*1.0);
    for(register int i=1;i<=700;++i)out_fire();
}
int main(){
    srand(20060725);
    cin>>n>>m>>r;
    for(register int i=1;i<=n;++i)cin>>b[i].x>>b[i].y>>b[i].r;
    for(register int i=1;i<=m;++i){
        cin>>e[i].x>>e[i].y;
        ansx+=e[i].x,ansy+=e[i].y;
    }
    doit();
    cout<<result<<endl;
}