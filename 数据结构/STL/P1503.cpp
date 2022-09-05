#include<cstdio>
#include<set>
const int M=50005;
using namespace std;
inline void read(int &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
}
int n,m,Buildings[M],iptl=0,temp;
char opt;
set<int>zzz;
int main(){
    read(n),read(m);
    zzz.insert(0),zzz.insert(n+1);
    for(register int i=1;i<=m;++i){
        scanf("%c",&opt);
        if(opt=='D'){
            read(temp);
            Buildings[iptl++]=temp;
            zzz.insert(temp);
        }else if(opt=='R'){
            zzz.erase(Buildings[--iptl]);
        }else{
            read(temp);
            auto it=zzz.lower_bound(temp);
            if(*it==temp){
                printf("0\n");
                continue;
            }
            printf("%d\n",(*it-*(--it))-1);
        }
    }
    return 0;
}