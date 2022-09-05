#include<bits/stdc++.h>
using namespace std;
namespace std1{
    unsigned long long A,B;
    void work(){
        char ch=getchar_unlocked();
        while(ch!='\n'){
            if(ch=='A')A=A*5+1;
            else if(ch=='T')A=A*5+2;
            else if(ch=='G')A=A*5+3;
            else if(ch=='C')A=A*5+4;
            ch=getchar_unlocked();
        }
        while(ch!=EOF){
            if(ch=='A')B=B*5+2;
            else if(ch=='T')B=B*5+1;
            else if(ch=='G')B=B*5+4;
            else if(ch=='C')B=B*5+3;
            ch=getchar_unlocked();
        }
        printf("%s\n",(A==B)?"Yes":"No");
    }
}
namespace std2{
    unsigned long long l,r,p,sum,opt;
    unsigned long long inv[10000005];
    const unsigned long long m=137438953471;
    unsigned long long Inv(unsigned long long x){
        if(x<10000000)return inv[x];
        else return (unsigned long long)(p-p/x)*Inv(p%x)%p;
    }
    void work(){
        scanf("%lld%lld%lld",&l,&r,&p);
        inv[1]=1;
        for(register int i=2;i<10000000;++i)
            inv[i]=(unsigned long long)(p-p/i)*inv[p%i]%p;
        for(register int i=l;i<=r;++i){
            sum+=Inv(i);
            if(sum>=m)sum-=m;
        }
        cout<<sum;
    }
}
namespace std3{
    int f[2005][2005];
    void work(){
        string a,b;
        cin>>a>>b;
        for(register int i=1;i<=a.size();++i)f[i][0]=i;
        for(register int i=1;i<=b.size();++i)f[0][i]=i;
        for(register int i=1;i<=a.size();++i)
        	for(register int j=1;j<=b.size();++j)
        		f[i][j]=min(min(f[i-1][j]+1,f[i][j-1]+1),f[i-1][j-1]+(a[i-1]!=b[j-1]));
        cout<<f[a.size()][b.size()];
    }
}
int main(){
    int opt;
    cin>>opt;
    if(opt==1)std1::work();
    else if(opt==2)std2::work();
    else std3::work();
}