#include<iostream>
#include<cmath> 
using namespace std;

int n;
string a,b;

int main(){
	cin>>n;
	if(n==1){
		cin>>a>>b;
		bool flag=true;
		if(a.size()!=b.size())cout<<"No"<<endl;
		else{
			for(int i=1,j=1;i<=a.size()&&j<=b.size();++i,++j){
				if(a[i]=='A'){
					if(b[i]!='T')flag=false;
					break;
				}
				else if(a[i]=='T'){
					if(b[i]!='A')flag=false;
					break;
				}
				else if(a[i]=='G'){
					if(b[i]!='C')flag=false;
					break;
				}
				else{
					if(b[i]!='G')flag=false;
					break;
				}
			}
		}
		if(flag==true)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
} 
