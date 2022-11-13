#include<bits/stdc++.h>
#define MAXN 10000100
using namespace std;
bitset<10000505>vis;
vector<int>ans;
inline bool check(int x){
    while(x){
        if(x%10==7)return true;
        x/=10;
    }
    return false;
}
inline void shai(){
    for(register int i=1;i<=MAXN;++i){
        if(vis[i])continue;
        if(check(i)){
            for(register int j=1;j*i<=MAXN;++j)
                vis[i*j]=true;
        }
    }
    for(register int i=1;i<=MAXN;++i)
        if(!vis[i])
            ans.push_back(i);
}
int main(){
    int t;
    shai();
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(vis[n]){
            cout<<-1<<endl;
            continue;
        }
        auto ptr=upper_bound(ans.begin(),ans.end(),n);
        cout<<*ptr<<endl;
    }
}