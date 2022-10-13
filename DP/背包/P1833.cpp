#include<bits/stdc++.h>
using namespace std;
int starth,startm,endh,endm,t;
int n,dp[1000005];
inline void zero_one(int cost,int value){
    for(register int j=t;j>=cost;--j)
        dp[j]=max(dp[j],dp[j-cost]+value);
}
inline void wanquan(int cost,int value){
    for(register int j=cost;j<=t;++j)
        dp[j]=max(dp[j],dp[j-cost]+value);
}
inline void erjinzhi(int cost,int value,int num){
    if(t<=cost*num){
        wanquan(cost,value);
        return;
    }
    for(register int k=1;k<num;k<<=1){
        zero_one(cost*k,value*k);
        num-=k;
    }
    zero_one(cost*num,value*num);
}
int main(){
    scanf("%d:%d %d:%d",&starth,&startm,&endh,&endm);
    t=endm+(60-startm)+60*(endh-starth-1);
    cin>>n;
    for(register int i=1;i<=n;++i){
        int x,y,z;
        cin>>x>>y>>z;
        if(z==0)wanquan(x,y);
        else erjinzhi(x,y,z);
    }
    cout<<dp[t];
}