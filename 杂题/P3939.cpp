#include<bits/stdc++.h>
using namespace std;
int n,m,temp,opt,l,r,c,a[300005];
vector<int>pos[300005];
int main(){
    cin>>n>>m;
    for(register int i=1;i<=n;++i){
        cin>>a[i];
        pos[a[i]].push_back(i);
    }
    while(m--){
        cin>>opt;
        if(opt==1){
            cin>>l>>r>>c;
            cout<<(upper_bound(pos[c].begin(),pos[c].end(),r)-lower_bound(pos[c].begin(),pos[c].end(),l))<<endl;
        }else{
            cin>>temp;
            (*lower_bound(pos[a[temp]].begin(),pos[a[temp]].end(),temp))++;
            (*lower_bound(pos[a[temp+1]].begin(),pos[a[temp+1]].end(),temp+1))--;
            swap(a[temp],a[temp+1]);
        }
    }
}