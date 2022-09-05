#include<bits/stdc++.h>
using namespace std;
#define IN stdin->_IO_read_ptr<stdin->_IO_read_end?*stdin->_IO_read_ptr++:__uflow(stdin)
#define OUT(_ch) stdout->_IO_write_ptr<stdout->_IO_write_end?*stdout->_IO_write_ptr++=_ch:__overflow(stdout,_ch)
inline void read(int &x){
	x=0;
	char ch=IN;
	while(ch<47)ch=IN;		
	while(ch>47)x=(x<<1)+(x<<3)+(ch^48),ch=IN;
}
void print(int x){
	if(x>9)print(x/10);
	OUT(x%10+48);
}
struct Interval{int l,r,v;};
struct SunList:forward_list<Interval>{
    iterator beg=before_begin();
    inline void push(Interval v){insert_after(beg,v);}
    SunList(int l,int r,int v){push({l,r,v});}
    SunList(int l1,int r1,int v1,int l2,int r2,int v2){push({l1,r1,v1}),push({l2,r2,v2});}
    SunList()=default;
    inline pair<Interval,SunList>Intersection(Interval &A,Interval &B){
        if(A.r<B.l||B.r<A.l)return {{-1,-1,0},SunList({A.l,A.r,A.v})};
	    else if((A.l>B.l&&A.r<B.r)||(A.l==B.l&&A.r==B.r)||(A.l>=B.l&&A.r<B.r)||(A.l>B.l&&A.r<=B.r))return {{A.l,A.r,B.v},SunList()};
	    else if(B.l>A.l&&B.r<A.r)return {B,SunList(A.l,B.l-1,B.v,B.r+1,A.r,B.v)};
	    else return {{A.l<B.l?B.l:A.l,A.l<B.l?A.r:B.r,B.v},SunList(A.l<B.l?A.l:B.r+1,A.l<B.l?B.l-1:A.r,B.v)};
    }
    inline SunList get(int l,int r){
        SunList Sec(l,r,0),answer;
        for(auto &upper:*this){
            SunList Temp;
            for(auto &under:Sec){
                auto result=move(Intersection(under,upper));
                if(result.first.l!=-1)answer.push(result.first);
                Temp.splice_after(Temp.beg,result.second);
            }
            if(Temp.empty())return answer;
            Sec=move(Temp);
        }
    }
    inline int query(int l,int r){
        auto S=move(get(l,r));
        int ans(0);
        for(auto &it:S)ans+=(it.r-it.l+1)*it.v;
        return ans;
    }
    inline void add(int l,int r,int v){
        auto S=move(get(l,r));
        for(auto &it:S)it.v+=v;
        splice_after(beg,S);
    }
    inline void to_sort(int l,int r){
        auto S=move(get(l--,r));
        S.sort([](Interval &A,Interval &B)->bool{return A.v<B.v;});
        for(auto &it:S){
            push({l+1,l+1+it.r-it.l,it.v});
            l+=it.r-it.l+1;
        }
    }
};
SunList SL(1,200000,0);
int main(int argc,char* argv[]){
    int n,opt,l,r,v;
    read(n);
    for(register int i=1;i<=n;++i){
        read(opt),read(l),read(r);
        if(opt==1){
            read(v);
            SL.push({l,r,v});
        }else if(opt==2){
            print(SL.query(l,r));
            OUT('\n');
        }
        else if(opt==3)SL.to_sort(l,r);
        else{
            read(v);
            SL.add(l,r,v);
        }
        if(i%100000==0)SL=SL.get(1,n);
    }
}