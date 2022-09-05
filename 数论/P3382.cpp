#include<bits/stdc++.h>
using namespace std;
int n;
double eps=1e-7,L,R,a[20];
inline double cost(double x){
    double sum=0;
    for(int i=0;i<=n;++i)
        sum=sum*x+a[i];
    return sum;
}
int main(){
    cin>>n>>L>>R;
    for(register int i=0;i<=n;++i)cin>>a[i];
    while(fabs(L-R)>=eps){
        double mid=(L+R)/2;
        if(cost(mid+eps)>cost(mid-eps))L=mid;
        else R=mid;
    }
    printf("%.5lf",R);
}