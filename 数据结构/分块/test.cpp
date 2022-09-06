#include<bits/stdc++.h>
using namespace std;
int d[]={0,7,7,7,7,7,7,7,7,7,8};
inline int logalgor(int k){
    int L=1,R=10;
    if(d[L]>=k)return 0;
    while(L<R){
        int mid=(L+R)>>1;
        if(d[mid]>=k)R=mid;
        else L=mid+1;
    }
    return L-1;
}
int main(){
    cout<<logalgor(9)<<endl;
}