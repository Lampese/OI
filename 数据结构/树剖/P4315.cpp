#include <bits/stdc++.h>
#define MAXN 100005
#define IT set<node>::iterator
using namespace std;
int n, cnt, nowtime, fa[MAXN], son[MAXN], top[MAXN], dep[MAXN], siz[MAXN], dis[MAXN], dfn[MAXN], id1[MAXN], id2[MAXN], val[MAXN], head[MAXN];
struct node
{
    int l, r;
    mutable int val;
    node(int L, int R = -1, int V = 0) : l(L), r(R), val(V) {}
    bool operator<(const node &o) const
    {
        return l < o.l;
    }
};
set<node>s;
inline IT split(int pos)
{
    IT it = s.lower_bound(node(pos));
    if (it != s.end() && it->l == pos)
        return it;
    --it;
    int L = it->l, R = it->r, V = it->val;
    s.erase(it);
    s.insert(node(L, pos - 1, V));
    return s.insert(node(pos, R, V)).first;
}
inline void basic_assign(int l, int r, int val)
{
    IT itr = split(r + 1), itl = split(l);
    s.erase(itl, itr);
    s.insert(node(l, r, val));
}
inline void basic_update(int l, int r, int val)
{
    IT itr = split(r + 1), itl = split(l);
    for (; itl != itr; itl++)
        itl->val += val;
}
inline int basic_query(int l, int r)
{
    int res = 0;
    IT itr = split(r + 1), itl = split(l);
    for (; itl != itr; itl++)
        res = max(res, itl->val);
    return res;
}
struct Edge
{
    int next, to, dis, id;
} e[MAXN << 1];
inline void add(int u, int v, int w, int id)
{
    e[++cnt].next = head[u];
    head[u] = cnt;
    e[cnt].to = v;
    e[cnt].dis = w;
    e[cnt].id = id;
}
inline void dfs1(int x, int father, int deep)
{
    fa[x] = father;
    dep[x] = deep;
    siz[x] = 1;
    int maxson = -1;
    for (int i = head[x]; i; i = e[i].next)
    {
        int y = e[i].to;
        if (y == father)
            continue;
        id1[e[i].id] = y;
        id2[e[i].id] = x;
        val[y] = e[i].dis;
        dfs1(y, x, deep + 1);
        siz[x] += siz[y];
        if (siz[y] > maxson)
        {
            maxson = siz[y];
            son[x] = y;
        }
    }
}
inline void dfs2(int x, int topp)
{
    top[x] = topp, dfn[x] = ++nowtime;
    s.insert(node(nowtime, nowtime, val[x]));
    if (!son[x])
        return;
    dfs2(son[x], topp);
    for (int i = head[x]; i; i = e[i].next)
    {
        int y = e[i].to;
        if (y == fa[x] || y == son[x])
            continue;
        dfs2(y, y);
    }
}
inline void assign(int x, int y, int val)
{
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        basic_assign(dfn[top[x]], dfn[x], val);
        x = fa[top[x]];
    }
    if (dep[x] < dep[y])
        swap(x, y);
    basic_assign(dfn[y] + 1, dfn[x], val);
}
inline void update(int x, int y, int val)
{
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        basic_update(dfn[top[x]], dfn[x], val);
        x = fa[top[x]];
    }
    if (dep[x] < dep[y])
        swap(x, y);
    basic_update(dfn[y] + 1, dfn[x], val);
}
inline int query(int x, int y)
{
    int res = 0;
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        res = max(res, basic_query(dfn[top[x]], dfn[x]));
        x = fa[top[x]];
    }
    if (dep[x] < dep[y])
        swap(x, y);
    res = max(res, basic_query(dfn[y] + 1, dfn[x]));
    return res;
}
inline int read()
{
    int res = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        res = res * 10 + ch - '0';
        ch = getchar();
    }
    return res * f;
}
string opt;
int main()
{
    n = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read(), w = read();
        add(u, v, w, i), add(v, u, w, i);
    }
    dfs1(1, 0, 1);
    dfs2(1, 1);
    while (true)
    {
        cin >> opt;
        if (opt == "Stop")
            break;
        int u = read(), v = read();
        if (opt == "Max")
            printf("%d\n", query(u, v));
        if (opt == "Add")
        {
            int w = read();
            update(u, v, w);
        }
        if (opt == "Cover")
        {
            int w = read();
            assign(u, v, w);
        }
        if (opt == "Change")
            assign(id2[u], id1[u], v);
    }
}