#include<bits/stdc++.h>
using namespace std;
deque<int>p,q;
int main(){
    int n,k,temp,a[1000005];
    cin>>n>>k;
    for(register int i=1;i<=n;++i){
        cin>>temp;
        while(!q.empty()){
            if(q.front()+k<=i)q.pop_front(),p.pop_front();
            else break;
        }
        if(p.empty())p.push_back(temp),q.push_back(i);
        else{
            while(!p.empty())
                if(p.back()>temp)
                    p.pop_back(),q.pop_back();
                else break;
            p.push_back(temp),q.push_back(i);
        }
        if(i>=k)cout<<p.front()<<" ";
        a[i]=temp;
    }
    cout<<endl;
    p.clear(),q.clear();
    for(register int i=1;i<=n;++i){
        temp=a[i];
        while(!q.empty()){
            if(q.front()+k<=i)q.pop_front(),p.pop_front();
            else break;
        }
        if(p.empty())p.push_back(temp),q.push_back(i);
        else{
            while(!p.empty())
                if(p.back()<temp)
                    p.pop_back(),q.pop_back();
                else break;
            p.push_back(temp),q.push_back(i);
        }
        if(i>=k)cout<<p.front()<<" ";
    }
}