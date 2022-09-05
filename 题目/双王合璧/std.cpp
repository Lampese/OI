#include<bits/stdc++.h>
using namespace std;
bitset<300000>stree,tag;
#define pushup(now) stree[now]=stree[now<<1]^stree[now<<1|1]
inline void read(int &x){
	x=0;
	char ch=getchar_unlocked();
	while(ch<'0'||ch>'9')ch=getchar_unlocked();
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar_unlocked();
	}
}
inline bool read_big(){
    char last,ch=getchar_unlocked();
    while(ch<'0'||ch>'9')ch=getchar_unlocked();
    while(ch>='0'&&ch<='9'){
        last=ch;
        ch=getchar_unlocked();
    }
    return last&1;
}
inline void givetag(int now,int l,int r){
    if(l==r)stree[now]=!stree[now];
    else tag[now]=!tag[now];
}
inline void pushdown(int now,int l,int r){
    int mid=(l+r)>>1;
    givetag(now<<1,l,mid);
    givetag(now<<1|1,mid+1,r);
    tag[now]=0;
}
void build(int now,int l,int r){
    if(l==r){
        stree[now]=read_big();
        return;
    }
    int mid=(l+r)>>1;
    build(now<<1,l,mid);
    build(now<<1|1,mid+1,r);
    pushup(now);
}
void change(int now,int l,int r,int left,int right){
    if(tag[now])pushdown(now,left,right);
    if(left>=l&&right<=r){
        givetag(now,left,right);
        return;
    }else if(left>r||right<l)return;
    else{
        int mid=(left+right)>>1;
        change(now<<1,l,r,left,mid);
        change(now<<1|1,l,r,mid+1,right);
    }
    pushup(now);
}
bool query(int now,int l,int r,int left,int right){
    if(tag[now])pushdown(now,left,right);
    if(left>=l&&right<=r)return stree[now];
    if(left>r||right<l)return 0;
    int mid=(left+right)>>1;
    return query(now<<1,l,r,left,mid)^query(now<<1|1,l,r,mid+1,right);
}
int main(){
    int n,q,opt,l,r;
    bool temp;
    read(n),read(q);
    build(1,1,n);
    for(register int i=1;i<=q;++i){
        read(opt),read(l),read(r);
        if(opt==1){
            temp=read_big();
            if(temp)change(1,l,r,1,n);
        }else{
            if(query(1,l,r,1,n))putchar_unlocked('Y'),putchar_unlocked('e'),putchar_unlocked('s');
            else putchar_unlocked('N'),putchar_unlocked('o');
            putchar_unlocked('\n');
        }
    }
}