二、阅读程序（程序输入不超过数组或字符串定义的范围；判断题正确填 √ ，错误填 × ；除特殊说明外，判断题 $1.5$ 分，选择题 $3$ 分，共计 $40$ 分）

#### **(1)**

```cpp
#include<bits/stdc++.h>
using namespace std;
struct _{unsigned key,next;}e[120000];
unsigned N,k,head[65536],i,ecnt;
char opt;
int main(){
    cin>>N;
    while(N--){
        cin>>c>>k;
        i=k&65535;
        if(opt=='1')e[++ecnt]={k,head[i]},head[i]=ecnt;
        else{
            for(i=head[i];i&&k!=e[i].key;i=e[i].next);
            putchar(i?'1':'0');
        }
    }
}
```

**假设输入的所有数的绝对值都不超过 $2^{31}-1$ ，完成下面的判断题和单选题：**

**判断题**

16. 将第 8 行中的 `N--` 更换为 `N=N-1`，不会影响程序的运行结果（     ）。

17. 将第 4 行中的 `unsigned` 更换为 `int`，不会影响程序的运行结果（     ）。

18. 将第 14 行中的 `putchar` 更换为 `printf`，不会影响程序的运行结果（     ）。

19. （2 分）当输入为

    ```
    5
    5
    1 23
    2 44
    2 23
    1 24235
    2 24235
    ```

    时，输出为 `011`（     ）。

**单选题**

20. 代码第 10 行的语句替换为（      ）不会影响程序的运行结果。

    A. `i=k%65535`

    B. `i=k%65536`

    C. `i=k&65536`

    D. `i=k&32768`

21. （2.5 分）这段代码的含义为（      ）。

    A. 二次探测法实现的 HashSet

    B. 拉链法实现的 HashSet

    C. 二次探测法实现的 HashMap

    D. 拉链法实现的 HashMap

#### **(2)**

```cpp
#include<bits/stdc++.h>
#define MAXN 1000005
using namespace std;
int n,m,cnt,arr[MAXN],d[MAXN],belong[MAXN],l[MAXN],r[MAXN],mark[MAXN];
inline void build(){
    int blocksize=sqrt(n),cnt=n/blocksize;
    if(n%blocksize)++cnt;
    for(int i=1;i<=cnt;++i){
        l[i]=blocksize*(i-1)+1;
        r[i]=blocksize*i;
    }
    r[cnt]=n;
    for(int i=1;i<=n;++i){
        belong[i]=(i-1)/blocksize+1;
        d[i]=arr[i];
    }
    for(int i=1;i<=cnt;++i)sort(d+l[i],d+1+r[i]);
}
inline void modify(int L,int R,int V){
    if(belong[L]==belong[R]){
        for(int i=L;i<=R;++i)arr[i]+=V;
        for(int i=l[belong[L]];i<=r[belong[L]];++i)d[i]=arr[i];
        sort(d+l[belong[L]],d+1+r[belong[L]]);
        return;
    }
    for(int i=L;i<=r[belong[L]];++i)arr[i]+=V;
    for(int i=l[belong[L]];i<=r[belong[L]];++i)d[i]=arr[i];
    sort(d+l[belong[L]],d+1+r[belong[L]]);
    for(int i=belong[L]+1;i<belong[R];++i)mark[i]+=V;
    for(int i=l[belong[R]];i<=R;++i)arr[i]+=V;
    for(int i=l[belong[R]];i<=r[belong[R]];++i)d[i]=arr[i];
    sort(d+l[belong[R]],d+1+r[belong[R]]);
}
inline int logalgor(int block,int k){
    int L=l[block],R=r[block];
    while(L<R){
        int mid=(L+R)>>1;
        if(d[mid]+mark[block]>=k)R=mid;
        else L=mid+1;
    }
    if(r[block]==L&&d[L]+mark[block]<k)return 0;
    return r[block]-L+1;
}
inline int find(int L,int R,int k){
    int ans=0;
    if(belong[L]==belong[R]){
        for(int i=L;i<=R;++i)
            if(arr[i]+mark[belong[L]]>=k)
                ++ans;
        return ans;
    }
    for(int i=L;i<=r[belong[L]];++i)
        if(arr[i]+mark[belong[L]]>=k)
            ++ans;
    for(int i=belong[L]+1;i<belong[R];++i)ans+=logalgor(i,k);
    for(int i=l[belong[R]];i<=R;++i)
        if(arr[i]+mark[belong[R]]>=k)
            ++ans;
    return ans;
}
int main(){
    char opt;
    int l,r,v;
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>arr[i];
    build();
    for(int i=1;i<=m;++i){
        cin>>opt>>l>>r>>v;
        if(opt=='M')modify(l,r,v);
        else cout<<find(l,r,v)<<endl;
    }
} 
```

**假设输入的所有数的绝对值都不超过 $2^{31}-1$ ，完成下面的判断题和单选题：**

**判断题**

22. 将第 6 行替换为 `int blocksize=sqrt(n),cnt=sqrt(n) `，不影响程序的运行结果（     ）。
23. 将代码中全部的 `sort` 上界中的 `+1` 去除，不影响程序的运行结果（     ）。
24. 
