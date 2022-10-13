#include<iostream>
#include<cstdio>
using namespace std;
const int N=100;
struct node{
    int l,r,sum;
    node operator +(const node &x)const{
        return {l,x.r,sum+x.sum};
    }
}stree[N<<2];
#define pushup(now) stree[now]=stree[now<<1]+stree[now<<1|1]
int arr[N];
void build(int now,int l,int r){
    if(l==r){
        stree[now]={l,l,arr[l]};
        return;
    }
    int mid=(l+r)>>1;
    build(now<<1,l,mid);
    build(now<<1|1,mid+1,r);
    pushup(now);
}
int query(int now,int l,int r){
    if(stree[now].l>=l&&stree[now].r<=r)return stree[now].sum;
    if(stree[now].l>r||stree[now].r<l)return 0;
    return query(now<<1,l,r)+query(now<<1|1,l,r);
}
void update(int now,int k,int v,int l,int r){
    if(l==r&&l==k){
        stree[now].sum+=v;
        return;
    }
    int mid=(l+r)>>1;
    if(k<=mid)update(now<<1,k,v,l,mid);
    else update(now<<1|1,k,v,mid+1,r);
    pushup(now);
}
int main(){
    return 0;
}
