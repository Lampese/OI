#include<bits/stdc++.h>
#define MAXN 400005
#define MAXM 250
using namespace std;
int n,m,last,blocksize,cnt;
int l[MAXN],r[MAXN],belong[MAXN],B[MAXN],pre[MAXN],sum[MAXM][MAXN];
bitset<MAXN>vis;
struct _data{
    int id,origin,rank;
}arr[MAXN];
struct node{
    int num=0,rank=0;
}p[MAXM][MAXM];
inline bool cmp1(_data &x,_data &y){return x.origin<y.origin;}
inline bool cmp2(_data &x,_data &y){return x.id<y.id;}
inline void prework(){
    blocksize=sqrt(n),cnt=n/blocksize;
    if(n%blocksize)++cnt;
    for(int i=1;i<=cnt;++i){
        l[i]=blocksize*(i-1)+1;
        r[i]=blocksize*i;
    }
    r[cnt]=n;
    for(int i=1;i<=n;++i)belong[i]=(i-1)/blocksize+1;
    for(register int i=1;i<=cnt;++i){
        memset(B,0,sizeof(B));
        node temp;
        for(register int j=i;j<=cnt;++j){
            for(register int k=l[j];k<=r[j];++k){
                ++B[arr[k].rank];
                if(B[arr[k].rank]>temp.rank)
                    temp={arr[k].rank,B[arr[k].rank]};
                else if(B[arr[k].rank]==temp.rank)
                    temp={min(temp.num,arr[k].rank),B[arr[k].rank]};
            }
            p[i][j]=temp;
        }
    }
    for(register int i=1;i<=cnt;++i){
        for(register int j=1;j<=n;++j)
            sum[i][arr[j].rank]=sum[i-1][arr[j].rank];
        for(register int j=l[i];j<=r[i];++j)
            ++sum[i][arr[j].rank];
    }
}
int main(){
    cin>>n>>m;
    for(register int i=1;i<=n;++i){
        cin>>arr[i].origin;
        arr[i].id=i;
    }
    sort(arr+1,arr+n+1,cmp1);
    arr[0]={0,-1,0};
    for(register int i=1;i<=n;++i){
        arr[i].rank=arr[i-1].rank;
        if(arr[i].origin!=arr[i-1].origin)
            ++arr[i].rank;
        pre[arr[i].rank]=arr[i].origin;
    }
    sort(arr+1,arr+n+1,cmp2);
    prework();
    int L,R;
    for(register int i=1;i<=m;++i){
        cin>>L>>R;
        L=(L+last-1)%n+1;
        R=(R+last-1)%n+1;
        if(L>R)swap(L,R);
        if(belong[R]-belong[L]<=2){
            int ans=0;
            for(register int j=L;j<=R;++j)B[arr[j].rank]=0;
            for(register int j=L;j<=R;++j){
                ++B[arr[j].rank];
                if(B[arr[j].rank]>B[ans])
                    ans=arr[j].rank;
                else if(B[arr[j].rank]==B[ans])
                    ans=min(ans,arr[j].rank);
            }
            cout<<(last=pre[ans])<<endl;
        }
        else{
            int ans=p[belong[L]+1][belong[R]-1].num;
            B[ans]=0,vis[ans]=0;
            for(register int j=L;j<=r[belong[L]];++j){
                B[arr[j].rank]=0;
                vis[arr[j].rank]=false;
            }
            for(register int j=l[belong[R]];j<=R;++j){
                B[arr[j].rank]=0;
                vis[arr[j].rank]=false;
            }
            for(register int j=L;j<=r[belong[L]];++j)++B[arr[j].rank];
            for(register int j=l[belong[R]];j<=R;++j)++B[arr[j].rank];
            node answer;
            for(register int j=L;j<=r[belong[L]];++j){
                if(!vis[arr[j].rank]){
                    vis[arr[j].rank]=true;
                    int value=B[arr[j].rank]+sum[belong[R]-1][arr[j].rank]-sum[belong[L]][arr[j].rank];
                    if(answer.rank<value)
                        answer={arr[j].rank,value};
                    else if(answer.rank==value)
                        answer={min(arr[j].rank,answer.num),value};
                }
            }
            for(register int j=l[belong[R]];j<=R;++j){
                if(!vis[arr[j].rank]){
                    vis[arr[j].rank]=true;
                    int value=B[arr[j].rank]+sum[belong[R]-1][arr[j].rank]-sum[belong[L]][arr[j].rank];
                    if(answer.rank<value)
                        answer={arr[j].rank,value};
                    else if(answer.rank==value)
                        answer={min(arr[j].rank,answer.num),value};
                }
            }
            if(answer.rank>B[ans]+p[belong[L]+1][belong[R]-1].rank)
                ans=answer.num;
            else if(answer.rank==B[ans]+p[belong[L]+1][belong[R]-1].rank)
                ans=min(answer.num,ans);
            cout<<(last=pre[ans])<<endl;
        }
    }
}