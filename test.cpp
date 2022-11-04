#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x = 0, w = 1;
    char ch = getchar();
    while ((ch < '0' ||
            ch > '9') &&
           ch != '-')
        ch = getchar();
    if (ch == '-')
    {
        w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * w;
}
const int N = 500005;
int n, m, cnt[205][205][1005], sum[205][205][1005], q, a[N], C[N], d[N], len, cntt, root[N];
long long summ[N];
bool cmp(int x, int y)
{
    return y < x;
}
void Discretize()
{
    sort(C + 1, C + 1 + m, cmp);
    len = unique(C + 1, C + 1 + m) - C - 1;
    for (int i = 1; i <= m; i++)
    {
        d[i] = lower_bound(C + 1, C + 1 + len, a[i]) - C;
        cout<<d[i]<<" ";
    }
    cout<<endl;
}
struct Node
{
    int l, r, siz;
    long long sum;
} tree[N << 5];
int build(int l, int r)
{
    int now = ++cntt;
    tree[now] = {0, 0, 0, 0};
    if (l < r)
    {
        int mid = (l + r) >> 1;
        tree[now].l = build(l, mid);
        tree[now].r = build(mid + 1, r);
    }
    return now;
}
int modify(int now, int l, int r, int v)
{
    cout<<l<<" "<<r<<endl;
    int to = ++cntt;
    tree[to] = tree[now];
    tree[to].siz = tree[now].siz + 1;
    tree[to].sum = tree[now].sum + C[v];
    if (l < r)
    {
        int mid = (l + r) >> 1;
        if (v <= mid)
            tree[to].l = modify(tree[now].l, l, mid, v);
        else
            tree[to].r = modify(tree[now].r, mid + 1, r, v);
    }
    return to;
}
long long query(int x, int y, int l, int r, int v)
{
    //cout<<x<<" "<<y<<" "<<l<<" "<<r<<" "<<v<<endl;
    if (l == r)
    {
        return tree[y].sum - tree[x].sum;
    }
    if (!v)
        return 0;
    int mid = (l + r) >> 1;
    int siz = tree[tree[y].l].siz - tree[tree[x].l].siz;
    if (v <= siz)
        return query(tree[x].l, tree[y].l, l, mid, v);
    else
        return tree[tree[y].l].sum - tree[tree[x].l].sum + query(tree[x].r, tree[y].r, mid + 1, r, v - siz);
}
int main()
{
    m = read();
    for (int i = 1; i <= m; i++)
    {
        a[i] = read();
        C[i]=a[i];
        summ[i] = summ[i - 1] + a[i];
    }
    Discretize();
    // root[0] = build(1, len);
    // for (int i = 1; i <= m; i++){
    //     root[i] = modify(root[i - 1], 1, len, d[i]);
    //     cout<<endl;
    // }
    // int x,y,h;
    // cin>>x>>y>>h;
    // cout<<query(root[x-1],root[y],1,len,h)<<endl;
}
