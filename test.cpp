#include<bits/stdc++.h>
using namespace std;
int main(){
    char next='a';
    int n;
    cin>>n;
    for(register int i=1;i<=n;++i){
        if(next>'z')next='b';
        cout<<next;
        ++next;
    }
}