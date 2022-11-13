#include<bits/stdc++.h>
using namespace std;
double d1,c,d2,p,ans=1e9;
int n;
vector<pair<double,double>>z;
inline void dfs(double cost,double now,int where){
    if(cost>ans)return;
    if((d1-z[where].second)<(now*d2)){
        ans=fmin(ans,cost);
        return;
    }
    for(register int i=1;i<z.size();++i){
        if(i==where)continue;
        if(z[where].first>z[i].first)continue;
        if()dfs();
    }
}
inline bool cmp(pair<double,double>a,pair<double,double>b){
    return a.first<b.first;
}
int main(){
    cin>>d1>>c>>d2>>p>>n;
    while(n--){
        double x,y;
        z.push_back({x,y});
    }
    sort(z.begin(),z.end(),cmp);
}