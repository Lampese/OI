#include<bits/stdc++.h>
#include<bits/extc++.h>
#define MAXN 1000005
using namespace __gnu_cxx;
using namespace std;
int n,x,cnt=-1;
crope *now[MAXN];
int main(){
    cin>>n;
    char opt,ch;
    now[++cnt]=new crope();
    while(n--){
        cin>>opt;
        if(opt=='T'){
            cin>>ch; 
            ++cnt;
            now[cnt]=new crope(*now[cnt-1]);
            now[cnt]->push_back(ch);
        }else if(opt=='U'){
            cin>>x;
            ++cnt;
            now[cnt]=new cropBurnside引理e(*now[cnt-x-1]);
        }else{
            cin>>x;
            cout<<now[cnt]->at(x)<<endl;
        }
    }
}