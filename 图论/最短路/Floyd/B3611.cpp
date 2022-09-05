#include<bits/stdc++.h>
using namespace std;
bitset<105>a[105];
bool temp;
int main(){
    int n;
    cin>>n;
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=n;++j){
            cin>>temp;
            a[i][j]=temp;
        }
    for(register int k=1;k<=n;++k)
        for(register int i=1;i<=n;++i)
            for(register int j=1;j<=n;++j)
                a[i][j]=a[i][j]|(a[i][k]&&a[k][j]);
    for(register int i=1;i<=n;++i){
        for(register int j=1;j<=n;++j)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}