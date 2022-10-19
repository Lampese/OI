#include<bits/stdc++.h>
using namespace std;
struct Node{
    int cnt;
    unordered_map<char,Node*>tree;
    Node():cnt(0){};
    void dfs(){
        for(auto p:tree){
            p.second->dfs();
            cnt+=p.second->cnt;
        }
    }
};
Node *root;
int main(){
    int T,n,q;
    string str;
    cin>>T;
    while(T--){
        cin>>n>>q;
        root=new Node;
        for(register int i=1;i<=n;++i){
            cin>>str;
            auto u=root;
            for(auto c:str)u=(u->tree[c]?u->tree[c]:u->tree[c]=new Node);
            ++u->cnt;
        }
        root->dfs();
        for(register int i=1;i<=q;++i){
            cin>>str;
            auto u=root;
            bool flag=true;
            for(auto c:str){
                if(u->tree[c])u=u->tree[c];
                else{
                    cout<<0<<endl;
                    flag=false;
                    break;
                }
            }
            if(!flag)continue;
            cout<<u->cnt<<endl;
        }
    }
}