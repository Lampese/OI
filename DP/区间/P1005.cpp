#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
struct BigInt:std::vector<int>{
	bool Positive=1;
    BigInt(int n=0){
    	if(n<0){
            Positive=0;
            n*=-1;
        }
        push_back(n);
        check();
    }
    inline BigInt& check(){
        while(!empty()&&!back())pop_back();
        if(empty())return *this;
        
        for(int i=1;i<size();++i){
            (*this)[i]+=(*this)[i-1]/10;
            (*this)[i-1]%=10;
        }
        while(back()>=10){
            push_back(back()/10);
            (*this)[size()-2]%=10;
        }
        return *this;
    }
    void AbsAdd(BigInt b){
        if((*this).size()<b.size())(*this).resize(b.size());
        for(int i=0;i!=b.size();++i)(*this)[i]+=b[i];
        (*this).check();
    }
};
std::istream& operator>>(std::istream &is,BigInt &n){
    std::string s;
    is>>s;
    n.clear();
    for(int i=s.size()-1;i>=0;--i){
    	if(s[i]=='-'){
    		n.Positive=0;
    		continue;
		}
    	n.push_back(s[i]-'0');
	}
    return is;
}
std::ostream& operator<<(std::ostream &os,const BigInt &n){
    if(n.empty())os<<0;
    if(n.Positive==0)os<<'-';
    for(int i=n.size()-1;i>=0;--i)os<<n[i];
    return os;
}
bool operator!=(const BigInt &a,const BigInt &b){
	if(a.Positive!=b.Positive)return 1;
    if(a.size()!=b.size())return 1;
    for(int i=a.size()-1;i>=0;--i)
        if(a[i]!=b[i])return 1;
    return 0;
}
bool operator==(const BigInt &a,const BigInt &b){
    return !(a!=b);
}
bool operator<(const BigInt &a,const BigInt &b){
	if(a.Positive>b.Positive)return 0;
	if(a.Positive<b.Positive)return 1;
    if(a.size()!=b.size())return a.size()<b.size();
    for(int i=a.size()-1;i>=0;--i)
        if(a[i]!=b[i])return a[i]<b[i];
    return 0;
}
bool operator>(const BigInt &a,const BigInt &b){
    return b<a;
}
bool operator<=(const BigInt &a,const BigInt &b){
    return !(a>b);
}
bool operator>=(const BigInt &a,const BigInt &b){
    return !(a<b);
}
BigInt AbsMinus(BigInt a,BigInt b){
    if(a<b)swap(a,b);
    for(int i=0;i!=b.size();a[i]-=b[i],++i)
    if(a[i]<b[i]){
        int j=i+1;
        while(!a[j])++j;
        while(j>i){
            --a[j];
            a[--j]+=10;
        }
    }
    return a.check();
}
BigInt& operator-=(BigInt &a,BigInt b){
    if(a.Positive!=b.Positive){
    	a.AbsAdd(b);
        return a;
	}else if(a.Positive==1&&a<b){
        a=AbsMinus(a,b);
        a.Positive=0;
        return a;
    }else if(a.Positive==0&&a<b)
        a.Positive=1;
    if(a<b)swap(a,b);
    for(int i=0;i!=b.size();a[i]-=b[i],++i)
        if(a[i]<b[i]){
            int j=i+1;
            while(!a[j])++j;
            while(j>i){
                --a[j];
                a[--j]+=10;
            }
        }
    return a.check();
}
BigInt operator-(BigInt a,const BigInt &b){
    return a-=b;
}
BigInt& operator+=(BigInt &a,const BigInt &b){
    BigInt c=b;
    c.Positive=!c.Positive;
    return a-=c;
}
BigInt operator+(BigInt a,const BigInt &b){
    return a+=b;
}
BigInt operator*(const BigInt &a,const BigInt &b){
    BigInt n;
    bool PFlag=a.Positive!=b.Positive?1:0;
    n.assign(a.size()+b.size()-1,0);
    for(int i=0;i!=a.size();++i)
        for(int j=0;j!=b.size();++j)
            n[i+j]+=a[i]*b[j];
    n.Positive=PFlag?0:1;
    return n.check();
}
BigInt& operator*=(BigInt &a,const BigInt &b){
    return a=a*b;
}
BigInt divmod(BigInt &a,const BigInt &b){
    BigInt ans;
    bool PFlag=a.Positive!=b.Positive?1:0;
    BigInt e=b;
    a.Positive=e.Positive=1;
    for(int t=a.size()-e.size();a>=e;--t){
        BigInt d;
        d.assign(t+1,0);
        d.back()=1;
        BigInt c=e*d;
        while(a>=c){
            a-=c;
            ans+=d;
        }
    }
    ans.Positive=(PFlag?0:1);
    return ans;
}
BigInt operator/(BigInt a,const BigInt &b){
    return divmod(a,b);
}
BigInt& operator/=(BigInt &a,const BigInt &b){
    return a=a/b;
}
BigInt& operator%=(BigInt &a,const BigInt &b){
    divmod(a,b);
    return a;
}
BigInt operator%(BigInt a,const BigInt &b){
    return a%=b;
}
BigInt& operator++(BigInt &a){
    a+=1;
    return a;
}
BigInt operator++(BigInt& a,int b){
	BigInt tmp=a;
    ++a;
    return tmp;
}
BigInt& operator--(BigInt &a){
    a-=1;
    return a;
}
BigInt operator--(BigInt& a,int b){
	BigInt tmp=a;
    --a;
    return tmp;
}
int n,m,a[MAXN];
BigInt p[MAXN],ans;
inline void init(){
    BigInt t=1;
    for(register int i=1;i<=100;++i){
        t*=2;
        p[i]=t;
    }
}
inline void dp(){
    BigInt f[MAXN][MAXN];
    for(register int i=1;i<=m;++i)f[i][i]=a[i]*p[m];
    for(register int l=2;l<=m;++l)
        for(register int i=1;i+l-1<=m;++i){
            int j=i+l-1;
            BigInt herei=a[i],herej=a[j];
            f[i][j]=max(f[i+1][j]+herei*p[m-(j-i)],f[i][j-1]+herej*p[m-(j-i)]);
        }
    ans+=f[1][m];
}
int main(){
    cin>>n>>m;
    init();
    for(register int i=1;i<=n;++i){
        for(register int j=1;j<=m;++j)cin>>a[j];
        dp();
    }
    cout<<ans<<endl;
}