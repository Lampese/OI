#include<bits/stdc++.h>
using namespace std;
vector<int>arr,arr_;
int temp;
int main(){
    while(cin>>temp){
        if(arr.empty()||temp<=arr.back())arr.push_back(temp);
        else *upper_bound(arr.begin(),arr.end(),temp,greater<int>())=temp;
        if(arr_.empty()||temp>arr_.back())arr_.push_back(temp);
        else *lower_bound(arr_.begin(),arr_.end(),temp)=temp;
    }
    cout<<arr.size()<<endl<<arr_.size()<<endl;
}