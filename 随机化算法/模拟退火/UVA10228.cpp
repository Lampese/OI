#include<bits/stdc++.h>
using namespace std;
int t,n;
double ans,sx,sy,ansx,ansy;
struct point{
    int x,y;
}points[105];
inline double calc(double x,double y){
    double result=0;
    for(register int i=1;i<=n;++i){
        double hx=points[i].x,hy=points[i].y;
        result+=sqrt((x-hx)*(x-hx)+(y-hy)*(y-hy));
    }
    return result;
}
inline void init(){
    ans=1e8;
    sx=sy=0;
}
inline void out_fire(){
    double T=3000,x=ansx,y=ansy;
    while(T>1e-15){
        double X=x+((rand()<<1)-RAND_MAX)*T;
        double Y=y+((rand()<<1)-RAND_MAX)*T;
        double now=calc(X,Y);
        double delta=now-ans;
        if(delta<0){
            ansx=X,ansy=Y;
            x=X,y=Y;
            ans=now;
        }else if(exp(-delta/T)*RAND_MAX>rand())x=X,y=Y;
        T*=(0.966);
    }
}
inline void doit(){
    ansx=sx/(n*1.0),ansy=sy/(n*1.0);
    for(register int i=1;i<=100;++i)
        out_fire();
}
int main(){
    srand(1e9+7);
    cin>>t;
    while(t--){
        init();
        cin>>n;
        for(register int i=1;i<=n;++i){
            cin>>points[i].x>>points[i].y;
            sx+=points[i].x,sy+=points[i].y;
        }
        doit();
        printf("%.0f\n",ans);
        if(t)puts("");
    }
}