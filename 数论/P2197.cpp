#include<bits/stdc++.h>
using namespace std;
int main(){
    int T,n,temp,sum;
    cin>>T;
    while(T--){
        cin>>n;
        n--;
        cin>>sum;
        while(n--){
            cin>>temp;
            sum^=temp;
        }
        if(!sum)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
}