#include<bits/stdc++.h>
#define MAXN 1005
using namespace std;
struct _{
    int cost,value;
};
int n,m,t,f[MAXN];
vector<_>b[MAXN];
int main(){
    cin>>m>>n;
    for(register int i=1;i<=n;++i){
        int cost,value,zu;
        cin>>cost>>value>>zu;
        t=max(t,zu);
        b[zu].push_back({cost,value});
    }
    for(register int i=1;i<=t;++i)
        for(register int j=m;j>=0;--j)
            for(auto v:b[i])
                if(j>=v.cost)
                    f[j]=max(f[j],f[j-v.cost]+v.value);
    cout<<f[m]<<endl;
}