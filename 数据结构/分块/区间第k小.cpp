#include<bits/stdc++.h>
#define For(from,to) for(int i=from;i<=to;++i)
int a[11],b[11],c[11],d[31],dtop(0);
inline int search(int k,int arr[11]){
	int l(0),r(10);
	while(l<=r){
		int mid=(l+r)>>1;
		if(arr[mid]<=k)l=mid+1;
		else r=mid-1;
	}
	return l-1;
}
signed main(){
    int k,l(0),r(0x7fffffff);
    scanf("%d",&k);
    srand((unsigned)time(NULL));
    For(1,10)d[++dtop]=a[i]=rand()%100+1;
    For(1,10)d[++dtop]=b[i]=rand()%100+1;
    For(1,10)d[++dtop]=c[i]=rand()%100+1;
    std::sort(a+1,a+11);std::sort(b+1,b+11);std::sort(c+1,c+11);std::sort(d+1,d+31);
    For(1,30)printf("%d ",d[i]);putchar('\n');
    while(l!=r){
        int mid=(l+r)>>1;
        if(search(mid,a)+search(mid,b)+search(mid,c)>=k)r=mid;
        else l=mid+1;
    }
    printf("%d\n",l);
}