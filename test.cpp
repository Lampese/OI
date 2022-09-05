#include<bits/stdc++.h>
using namespace std;
int main(){
    list<int>a={1,2,3,4,5,6,7,8,9,10};
    a.erase(--a.end());
    for(auto i:a)
        cout<<i<<" ";
}