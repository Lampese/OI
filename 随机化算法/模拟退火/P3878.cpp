#include<bits/stdc++.h>
#define MAXN 35
using namespace std;
int t,n,l,r,ans,mid,a[MAXN];
inline void init(){
    l=0,r=0;
    ans=(int)1e8;
}
inline int randint(int a,int b){
    return (rand()%(b-a+1))+a;
}
inline void doit(){
    double T=3144;
    while(T>1e-15){
        int x=randint(1,mid),y=randint(mid+1,n);
        int dis=abs((l-a[x]+a[y])-(r-a[y]+a[x]));
        double delta=dis-ans;
        if(delta<0){
            l=l-a[x]+a[y];
            r=r-a[y]+a[x];
            ans=dis;
            swap(a[x],a[y]);
        }else if(exp(-delta/T)*RAND_MAX>rand()){
            l=l-a[x]+a[y];
            r=r-a[y]+a[x];
            swap(a[x],a[y]);
        }
        T*=(0.95);
    }
}
int main(){
    srand(20060810);
    cin>>t;
    while(t--){
        init();
        cin>>n;
        mid=n/2;
        for(register int i=1;i<=n;++i){
            cin>>a[i];
            if(i<=mid)l+=a[i];
            else r+=a[i];
        }
        if(n==1){
            cout<<a[1]<<endl;
            continue;
        }
        for(register int i=1;i<=100;++i)doit();
        cout<<ans<<endl;
    }
}