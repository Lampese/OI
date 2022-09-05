#include<bits/stdc++.h>
#define MAXN 30005
using namespace std;
bitset<MAXN>tree;
struct _{
    int l,r,v;
}L[MAXN];
bool cmp(_ a,_ b){
    return a.r<b.r;
}
int ans,n,h;
int main(){
    cin>>n>>h;
    for(register int i=1;i<=h;++i)cin>>L[i].l>>L[i].r>>L[i].v;
    sort(L+1,L+h+1,cmp);
    for(register int i=1;i<=h;++i){
        int k(0);
        for(register int j=L[i].l;j<=L[i].r;++j)
            if(tree[j])++k;
        if(k>=L[i].v)continue;
        for(register int j=L[i].r;j>=L[i].l;--j){
            if(tree[j])continue;
            tree[j]=true;
            ++ans;++k;
            if(k==L[i].v)break;
        }
    }
    cout<<ans<<endl;
}