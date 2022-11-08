#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[5];
    cin>>a[1]>>a[2]>>a[3]>>a[4];
    sort(a+1,a+5);
    if(a[1]==1&&a[4]==9&&a[2]==4&&a[3]==7)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}