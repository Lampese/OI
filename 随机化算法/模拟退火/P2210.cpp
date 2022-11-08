#include<bits/stdc++.h>
#define MAXN 15
using namespace std;
int n,ans,fr[MAXN][5],pos[MAXN],dp[MAXN][MAXN];
inline int randint(int a,int b){
    return (rand()%(b-a+1))+a;
}
inline int rebuild(){
    int nowans=0;
    for(register int i=1;i<=n;++i){
        for(register int j=1;j<=3;++j){
            dp[i][fr[i][j]]=abs(pos[i]-pos[fr[i][j]]);
            if(i<fr[i][j])nowans+=dp[i][fr[i][j]];
        }
    }
    return nowans;
}
inline void out_fire(){
    double T=3443;
    while(T>1e-15){
        int x=1,y=1;
        while(x==y){
            x=randint(1,n);
            y=randint(1,n);
        }
        if(x>y)swap(x,y);
        swap(pos[x],pos[y]);
        int nowans=rebuild();
        double delta=ans-nowans;
        if(delta>0){
            ans=nowans;
            T*=0.96;
            continue;
        }else if(exp(delta/T)*RAND_MAX>rand()){
            ans=nowans;
            T*=0.96;
            continue;
        }
        T*=0.96;
        swap(pos[x],pos[y]);
        rebuild();
    }
}
int main(){
    srand(20060725);
    cin>>n;
    for(register int i=1;i<=n;++i)pos[i]=i;
    for(register int i=1;i<=n;++i){
        for(register int j=1;j<=3;++j){
            cin>>fr[i][j];
            dp[i][fr[i][j]]=abs(pos[i]-pos[fr[i][j]]);
            if(i<fr[i][j])ans+=dp[i][fr[i][j]];
        }
    }
    for(register int i=1;i<=100;++i)out_fire();
    cout<<ans<<endl;
}