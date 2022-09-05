#include<bits/stdc++.h>
using namespace std;
int a,b,p,sum,fa[100005];
bitset<100005>isPrime;
int Prime[100005],where,cnt;
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void GetPrime(int n){
	for(int i=2;i<=n;++i){
		if(!isPrime[i]){
            Prime[++cnt]=i;
            if(!where&&p<=i)where=cnt;
        }
		for(int j=1;j<=cnt&&i*Prime[j]<=n;++j){
			isPrime[i*Prime[j]]=1;
			if(i%Prime[j]==0)break;
		}
	}
}
int main(){
    cin>>a>>b>>p;
    sum=b-a+1;
    for(register int i=1;i<=b;++i)fa[i]=i;
    GetPrime(b);
    for(register int i=where;i<=cnt;++i){
        int P=Prime[i],temp=0;
        for(int j=a/P;j*P<=b;++j){
            if(j*P<a)continue;
            if(temp==0){
                temp=j*P;
                continue;
            }
            int x=temp,y=j*P;
            int fx=find(x),fy=find(y);
            if(fx!=fy){
                fa[fx]=fy;
                --sum;
            }
            temp=y;
        }
    }
    cout<<sum<<endl;
}