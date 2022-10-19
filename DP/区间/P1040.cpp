/*
一些小记：
关于这里为啥 r[i][j] =i 和 =j 都对的原因
前序遍历确实是不一样的，但这正好意味着一件事
这代表了我们对其区分出了左子树和右子树的区别
最根本的问题是，我们的处理方式+遍历方式可以保证：
    1.小的节点挂为根时，大的节点肯定在右子树
    2.大的节点挂为根时，小的节点肯定在左子树
因为处理的时候我们并没有去存叶子结点，叶子在左在右完全看他的那个根决定
我们的遍历是一直在查询 [i][j] 的根然后再查询左、右区间的根，这是按照区间顺序的（这个方式本来就是在尊重中序遍历正确的前提）
这个遍历方法刚好可以配合刚才的存储方式完成最底层左右节点的选取，令人拍手称妙
*/
#include<bits/stdc++.h>
#define MAXN 50
using namespace std;
int n,a[MAXN],f[MAXN][MAXN],r[MAXN][MAXN];
void print(int l,int R){
    if(l>R)return;
    cout<<r[l][R]<<" ";
    if(l==R)return;
    print(l,r[l][R]-1);
    print(r[l][R]+1,R);
}
void print_test(int l,int R){
    if(l>R)return;
    if(l==R){
        cout<<r[l][R]<<" ";
        return;
    }
    print_test(l,r[l][R]-1);
    cout<<r[l][R]<<" ";
    print_test(r[l][R]+1,R);
}
int main(){
    cin>>n;
    for(register int i=1;i<=n;++i){
        cin>>a[i];
        f[i][i]=a[i];
        r[i][i]=i;
    }
    for(register int len=2;len<=n;++len)
        for(register int i=1;i+len-1<=n;++i){
            int j=i+len-1;
            if(i+1==j){
                f[i][j]=f[j][j]+f[i][i];
                r[i][j]=j;
            }
            for(register int k=i;k<j;++k){
                if(f[i][j]<f[i][k-1]*f[k+1][j]+f[k][k]){
                    r[i][j]=k;
                    f[i][j]=f[i][k-1]*f[k+1][j]+f[k][k];
                }
            }
        }
    cout<<f[1][n]<<endl;
    print(1,n);
    cout<<endl;
    print_test(1,n);
}