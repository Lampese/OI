#include<bits/stdc++.h>
using namespace std;
set<unsigned>x;
int main(){
    unsigned N,ask,k;
    cin>>N;
    for(register int i=1;i<=N;++i){
        cin>>ask>>k;
        if(ask==1)x.insert(k);
        else if(x.find(k)!=x.end()){
            cout<<1;
        }else cout<<0;
    }
}