#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
const long long P=1e9+7;
struct Matrix{
    int n,m;
    long long M[MAXN][MAXN];
    inline void print(){
        for(register int i=1;i<=n;++i){
            for(register int j=1;j<=m;++j)
                cout<<M[i][j]<<" ";
            cout<<endl;
        }
    }
    Matrix operator*(const Matrix &x)const{
        Matrix result;
        result.n=n;
        result.m=x.m;
        for(register int i=1;i<=n;++i)
            for(register int j=1;j<=x.m;++j){
                result.M[i][j]=0;
                for(register int k=1;k<=x.n;++k){
                    result.M[i][j]=(result.M[i][j]+M[i][k]*x.M[k][j]%P)%P;
                    //cerr<<M[i][k]<<" "<<x.M[k][j]<<endl;
                }
            }
        return result;
    }
};
inline Matrix fastpow(Matrix A,long long p){
    --p;
    Matrix base=A;
    while(p){
        if(p&1)A=A*base;
        base=base*base;
        p>>=1;
    }
    return A;
} 
int main(){
    int T,n;
    cin>>T;
    Matrix A,B;
    A.n=A.m=3;
    A.M[1][1]=A.M[1][2]=A.M[2][3]=A.M[3][1]=1;
    A.M[1][3]=A.M[2][1]=A.M[2][2]=A.M[3][2]=A.M[3][3]=0;
    B.n=1,B.m=3;
    B.M[1][1]=B.M[1][2]=B.M[1][3]=1;
    while(T--){
        cin>>n;
        if(n<=3){
            cout<<1<<endl;
            continue;
        }
        cout<<(B*fastpow(A,(n-3))).M[1][1]<<endl;  
    }
}