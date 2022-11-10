#include<bits/stdc++.h>
using namespace std;
int k;
int main(){
    cin>>k;
    while(k--){
        long long n,d,e;
        cin>>n>>d>>e;
        long long paq=n-e*d+2;
        long long pmq=sqrt(paq*paq-4*n);
        long long p=(paq+pmq)/2;
        long long q=paq-p;
        if(min(p,q)<=0){
            cout<<"NO"<<endl;
            continue;
        } 
        if(n!=p*q){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<min(p,q)<<" "<<max(p,q)<<endl;
    }
}