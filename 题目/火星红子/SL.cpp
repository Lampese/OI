#include<bits/stdc++.h>
using namespace std;
struct Interval{int l,r,v;};
struct SunList:forward_list<Interval>{
    iterator beg=before_begin();
    inline void push(Interval v){insert_after(beg,v);}
    SunList(int l,int r,int v){push({l,r,v});}
    SunList(int l1,int r1,int v1,int l2,int r2,int v2){push({l1,r1,v1}),push({l2,r2,v2});}
    SunList()=default;
    inline pair<Interval,SunList> Intersection(Interval &A,Interval &B){
        if(A.r<B.l||B.r<A.l)return {{-1,-1,0},SunList(A.l,A.r,B.v)};
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
    inline int find(int k){
        for(auto &it:*this)
            if(k>=it.l&&k<=it.r)
                return it.v;
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
int main(){
    
}