#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
struct point{
    double dis;
    int color;
}p[MAXN];
inline bool cmp(const point &a,const point &b){
    return a.dis<b.dis;
}
inline double cost(double xa,double ya,double xb,double yb){
    return sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
}
int main(){
    double x,y,xx,yy;
    int n,color,ans(0);
    cin>>n>>x>>y;
    for(register int i=1;i<=n;++i){
        cin>>xx>>yy>>color;
        p[i]={cost(x,y,xx,yy),color};
    }
    sort(p+1,p+1+n,cmp);
    int r=0,b=0;
    for(register int i=1;i<=n;++i){
        if(p[i].color==1)++r;
        else ++b;
        if(r>=b)++ans;
    }
    cout<<ans<<endl;
}