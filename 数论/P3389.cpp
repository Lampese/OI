#include<bits/stdc++.h>
#define MAXN 110
#define eps 1e-6
using namespace std;
int n;
double a[MAXN][MAXN];
inline bool gauss(){
    for(register int i=1;i<=n;++i){
        int r(i);
        for(int j=i+1;j<=n;++j)
            if(fabs(a[r][i])<fabs(a[j][i]))
                r=j;
        if(r!=i)
            for(int j=1;j<=n+1;++j)
                swap(a[i][j],a[r][j]);
        if(fabs(a[i][i])<eps)return false;
        for(int j=1;j<=n;++j)
            if(j!=i){
                for(int k=i+1;k<=n+1;++k)
                    a[j][k]-=a[i][k]*(a[j][i]/a[i][i]);
            }
    }
    for(int i=1;i<=n;++i)a[i][n+1]/=a[i][i];
    return true;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n+1;++j)
            cin>>a[i][j];
    if(!gauss()){
        printf("No Solution\n");
        return 0;
    }
    for(int i=1;i<=n;++i)printf("%.2lf\n",a[i][n+1]);
}