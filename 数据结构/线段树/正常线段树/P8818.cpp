#include<bits/stdc++.h>
#define int long long
#define MAXN 100005
#define pushup(now) tree[now]=tree[now<<1]+tree[now<<1|1]
using namespace std;
int n,m,q;
struct segment_tree{
    int arr[MAXN];
    struct node{
        int l,r,uppermax,uppermin,undermax,undermin;
        node operator+(const node &x)const{
            return {l,x.r,max(uppermax,x.uppermax),min(uppermin,x.uppermin),max(undermax,x.undermax),min(undermin,x.undermin)};
        }
    }tree[MAXN<<2],NP={0,0,-1000000001,1000000001,-1000000001,1000000001};
    inline void build(int now,int l,int r){
        if(l==r){
            if(arr[l]>=0)tree[now]={l,r,arr[l],arr[l],-1000000001,1000000001}; 
            else tree[now]={l,r,-1000000001,1000000001,arr[l],arr[l]};
            return;
        }
        int mid=(l+r)>>1;
        build(now<<1,l,mid);
        build(now<<1|1,mid+1,r);
        pushup(now);
    }
    inline node query(int now,int l,int r){
        if(r<tree[now].l||tree[now].r<l)return NP;
        else if(l<=tree[now].l&&tree[now].r<=r)return tree[now];
        else return query(now<<1,l,r)+query(now<<1|1,l,r);
    }
}A,B;
signed main(){
    cin>>n>>m>>q;
    for(register int i=1;i<=n;++i)cin>>A.arr[i];
    for(register int i=1;i<=m;++i)cin>>B.arr[i];
    A.build(1,1,n),B.build(1,1,m);
    while(q--){
        int la,ra,lb,rb,ans=-1e18,Ax[5],Bx[5];
        cin>>la>>ra>>lb>>rb;
        segment_tree::node an=A.query(1,la,ra),bn=B.query(1,lb,rb);
        Ax[1]=an.undermax,Ax[2]=an.undermin,Ax[3]=an.uppermax,Ax[4]=an.uppermin;
        Bx[1]=bn.undermax,Bx[2]=bn.undermin,Bx[3]=bn.uppermax,Bx[4]=bn.uppermin;
        for(register int i=1;i<=4;++i){
            if(abs(Ax[i])==1000000001)continue;
            int nowans=1e18;
            for(register int j=1;j<=4;++j){
                if(abs(Bx[j])==1000000001)continue;
                nowans=min(nowans,Ax[i]*Bx[j]);
            }
            ans=max(ans,nowans);
        }
        cout<<ans<<endl;
    }
}