#include "testlib.h"
long long sum[100005],cnta,cntb;
int main(long long argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    long long n=inf.readLong(),a=inf.readLong(),b=inf.readLong(),k=0;
    for(register long long i=1;i<=n;++i){
        if((n+1-i)*i==b){
            k=i;
            break;
        }
    }
    if(!k){
        if(ouf.readLong()==-1)quit(_ok,"fuck");
        else quit(_wa,"fuck");
        return 0;
    }
    for(register long long i=1;i<=n;++i){
        long long temp=ouf.readLong();
        sum[i]=sum[i-1]+temp;
        if(sum[i]&1)++cntb;
        else ++cnta;
    }
    long long ji=cnta*cntb;
    if(b==ji)quit(_ok,"fuck");
    else quit(_wa,"fuck");
}