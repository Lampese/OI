#include<bits/stdc++.h>
using namespace std;
bitset<100005>isPrime;
int Prime[10005],cnt,ecnt;
void GetPrime(int n){
	for(int i=2;i<=n;++i){
		if(!isPrime[i])Prime[++cnt]=i;
		for(int j=1;j<=cnt&&i*Prime[j]<=n;++j){
			isPrime[i*Prime[j]]=1;
			if(i%Prime[j]==0)break;
		}
	}
}
int logalgor(int n){
    int l=1,r=cnt;
    while(l<r){
        int mid=(l+r)>>1;
        if(Prime[mid]>=n)r=mid;
        else l=mid+1;
    }
    return Prime[l];
}
int main(){
    int n,m,p;
    cin>>n>>m;
    GetPrime(100500);
    printf("%d %d\n",p=logalgor(n),p);
    for(register int i=1;i<n-1;++i){
        ++ecnt;
        printf("%d %d 1\n",i,i+1);
    }
    printf("%d %d %d\n",n-1,n,p-(n-2));
    for(register int i=1;i<=n;++i)
        for(register int j=i+2;j<=n;++j){
            if(ecnt==m-1)return 0;//m-1 是因为 n-1 到 n 的那条连边
            ++ecnt;
            printf("%d %d 100000000\n",i,j);
        }
}