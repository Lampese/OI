#include<bits/stdc++.h>
using namespace std;
inline bool check(int l,int r,int v){
    return (v>=l&&v<=r);
}
int t,n,q,pos,val,temp,opt,l,r,k;
int main(){
    scanf("%d",&t);
    while(t--){
        val=1000000005;
        scanf("%d%d",&n,&q);
        for(register int i=1;i<=n;++i){
            scanf("%d",&temp);
            if(temp<val){
                val=temp;
                pos=i;
            }
        }
        while(q--){
            scanf("%d%d%d",&opt,&l,&r);
            if(opt==1){
                if(check(l,r,pos))
                    pos=l;
            }else if(opt==2){
                if(check(l,r,pos))
                    pos=r;
            }else if(opt==3){
                if(check(l,r,pos))
                    pos=l+r-pos;
            }else{
                scanf("%d",&k);
                if(k>=r-l+1){
                    if(l<=pos&&pos<=r)pos+=k;
                    else if(l+k<=pos&&pos<=r+k)pos-=k;
                }else if(l<=pos&&pos<l+k){
                    int len=(r-pos+k)/k;
                    pos+=len*k;
                }else if(l+k<=pos&&pos<r+k)
                    pos-=k;
            }
        }
        cout<<pos<<endl;
    }
}