#include<bits/stdc++.h>
using namespace std;
struct Interval{int l,r;};
inline void Intersection(Interval A,Interval B){
    if(A.r<B.l||B.r<A.l){
        cout<<"NaN"<<endl;
        cout<<A.l<<' '<<A.r<<endl;
    }
	else if((A.l>B.l&&A.r<B.r)||(A.l==B.l&&A.r==B.r)||(A.l>=B.l&&A.r<B.r)||(A.l>B.l&&A.r<=B.r)){
        cout<<A.l<<' '<<A.r<<endl;
        cout<<"NaN"<<endl;
    }
	else if(B.l>A.l&&B.r<A.r){
        cout<<B.l<<' '<<B.r<<endl;
        cout<<A.l<<' '<<B.l-1<<' '<<B.r+1<<' '<<A.r<<endl;
    }
	else{
        cout<<(A.l<B.l?B.l:A.l)<<' '<<(A.l<B.l?A.r:B.r)<<endl;
        cout<<(A.l<B.l?A.l:B.r+1)<<' '<<(A.l<B.l?B.l-1:A.r)<<endl;
    }
} 
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    Intersection({a,b},{c,d});
}