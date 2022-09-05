#include<bits/stdc++.h>
using namespace std;
int a[11]={0,50,28,326};
inline int logalgor(int k){
    int l=1,r=3;
    while(l<r){
        int mid=(l+r)>>1;
        if(a[mid]>=k)r=mid;
        else l=mid+1;
    }
    return l;
}
int main(){
    cout<<R-logalgor(495)+1;
}