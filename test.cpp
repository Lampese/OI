#include<bits/stdc++.h>
using namespace std;
#define IN stdin->_IO_read_ptr<stdin->_IO_read_end?*stdin->_IO_read_ptr++:__uflow(stdin)
#define OUT(_ch) stdout->_IO_write_ptr<stdout->_IO_write_end?*stdout->_IO_write_ptr++=_ch:__overflow(stdout,_ch)
template<typename T>inline void read(T &x){
	x=0;
	char ch=IN;
	while(ch<47||ch>64)ch=IN;
	while(ch>47)x=(x<<1)+(x<<3)+(ch&15),ch=IN;
}
template<typename T>void P(T x){
	if(x>9)P(x/10);
	OUT(x%10+48);
}
list<int>dq[1000005];
int main(){
    int x,y,q;
    read(q);
    while(q--){
        char ch=IN;
        while(ch<64)ch=IN;
        if(ch=='s'){
            read(x);
            P(dq[x].size()),OUT('\n');
        }
        else if(ch=='f'){
            read(x);
            if(!dq[x].empty())P(*dq[x].begin()),OUT('\n');
        }
        else if(ch=='b'){
            read(x);
            if(!dq[x].empty())P(*(--dq[x].end())),OUT('\n');
        }else{
            IN,IN,IN,ch=IN;
            if(ch=='b'){
                read(x);
                if(!dq[x].empty())dq[x].pop_back();
            }
            else if(ch=='f'){
                read(x);
                if(!dq[x].empty())dq[x].pop_front();
            }else{
                ch=IN;
                read(x),read(y);
                if(ch=='b')dq[x].push_back(y);
                else dq[x].push_front(y);
            }
        }
    }
}