#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
long long n,ans;
struct node{
    long long time,dis;
    bool operator <(const node &x)const{return time<x.time;}
}arr[MAXN];
priority_queue<long long,vector<long long>,greater<long long>>q;
signed main(){
    cin>>n;
    for(register long long i=1;i<=n;++i)cin>>arr[i].time>>arr[i].dis;
    sort(arr+1,arr+n+1);    max();
    for(register long long i=1;i<=n;++i){
        if(arr[i].time<=q.size()){
            if(arr[i].dis>q.top()){
                ans-=q.top();
                q.pop();
                q.push(arr[i].dis);
                ans+=arr[i].dis;
            }
        }else{
            q.push(arr[i].dis);
            ans+=arr[i].dis;
        }
    }
    cout<<ans<<endl;
}