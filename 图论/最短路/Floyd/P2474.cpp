/*
i=j <=> 0<=i-j<=0

i-j>=0 i-j<=0 

s:i->j 0
l:i->j 0

i<j <=> -2<=i-j<=-1

i-j>=-2 j-i<=2
i-j<=-1

s:i->j -2
l:i->j -1

i>j <=> 1<=i-j<=2

i-j>=1 j-i<=-1
i-j<=2

s:i->j 1
l:i->j 2

i?j <=> -2<=i-j<=2

i-j>=-2 j-i<=2
i-j<=2

s:i->j 2
l:i->j -2
*/ 
#include<bits/stdc++.h>
using namespace std;
int n,a,b,ans1,ans2,ans3,maxx[55][55],minn[55][55];
char temp;
int main(){
    cin>>n>>a>>b;
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=n;++j){
            cin>>temp;
            if(temp=='='||i==j){
				maxx[i][j]=0;
				minn[i][j]=0;
			}
			else if(temp=='-'){
				maxx[i][j]=-1;
				minn[i][j]=-2;
			}
			else if(temp=='+'){
				maxx[i][j]=2;
				minn[i][j]=1;
			}
			else if(temp=='?'){
				maxx[i][j]=2;
				minn[i][j]=-2;
			}
        }
    for(register int k=1;k<=n;++k)
        for(register int i=1;i<=n;++i)
            for(register int j=1;j<=n;++j){
                if(i!=j&&j!=k&&i!=j){
                    maxx[i][j]=min(maxx[i][j],maxx[i][k]+maxx[k][j]);
                    minn[i][j]=max(minn[i][j],minn[i][k]+minn[k][j]);
                }
            }
    /*
    A+B>i+j
    A-i>j-B

    A+B=i+j
    A-i=j-B

    A+B<i+j
    A-i<j-B
    i-A>B-j
    */
    for(register int c=1;c<=n;++c)
        for(register int d=1;d<c;++d){  
            if(c==a||c==b||d==a||d==b) continue;
			if(minn[a][c]>maxx[d][b]||minn[a][d]>maxx[c][b])++ans1;
			else if((maxx[a][c]==minn[a][c]&&maxx[d][b]==minn[d][b]&&maxx[a][c]==minn[d][b])||(maxx[a][d]==minn[a][d]&&maxx[c][b]==minn[c][b]&&maxx[a][d]==minn[c][b]))++ans2;
			else if(maxx[a][c]<minn[d][b]||maxx[a][d]<minn[c][b])++ans3;
        }
    cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
}