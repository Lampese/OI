#include<bits/stdc++.h>
using namespace std;
int f[3000005],a[3000005];
int main(){
    stack<int>s;
    int n;
    cin>>n;
    for(register int i=1;i<=n;++i){
        cin>>a[i];
        while(!s.empty()){
            if(a[i]>a[s.top()])f[s.top()]=i,s.pop();
            else break;
        }
        s.push(i);
    }
    for(register int i=1;i<=n;++i)
        cout<<f[i]<<" ";
}