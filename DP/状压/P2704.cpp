#include <bits/stdc++.h>
#define IN stdin->_IO_read_ptr < stdin->_IO_read_end ? *stdin->_IO_read_ptr++ : __uflow(stdin)
template <typename T>
inline void read(T &x)
{
    x = 0;
#ifdef read_fs
    int w(1);
#endif
    char ch = IN;
    while (ch < 47)
    {
#ifdef read_fs
        if (ch == '-')
            w = -1;
#endif
        ch = IN;
    }
    while (ch > 47)
        x = (x << 1) + (x << 3) + (ch & 15), ch = IN;
#ifdef read_fs
    if (w < 0)
        x = -x;
#endif
}
using namespace std;
long long n, m, ans, f[(1 << 10)][(1 << 10)][3], a[105], Ss[(1 << 10)];
char x;
inline long long check(long long S)
{
    long long cnt = 0;
    while (S)
    {
        if (S & 1)
            ++cnt;
        S >>= 1;
    }
    return cnt;
}
signed main()
{
    read(n), read(m);
    for (long long i = 0; i < n; ++i)
        for (long long j = 0; j < m; ++j)
            cin >> x, a[i] <<= 1, a[i] += (x == 'H' ? 1 : 0);
    for (long long i = 0; i < (1 << m); ++i)
        Ss[i] = check(i);
    for (long long S = 0; S < (1 << m); ++S)
        if (!(S & a[0] || (S & (S << 1)) || (S & (S << 2))))
            f[0][S][0] = Ss[S];
    for (long long L = 0; L < (1 << m); ++L)
        for (long long S = 0; S < (1 << m); ++S)
            if (!(L & S || L & a[0] || S & a[1] || (L & (L << 1)) || (L & (L << 2)) || (S & (S << 1)) || (S & (S << 2))))
                f[L][S][1] = Ss[S] + Ss[L];
    for (long long i = 2; i < n; ++i)
        for (long long L = 0; L < (1 << m); ++L)
        {
            if (L & a[i - 1] || (L & (L << 1)) || (L & (L << 2)))
                continue;
            for (long long S = 0; S < (1 << m); ++S)
            {
                if (S & a[i] || L & S || (S & (S << 1)) || (S & (S << 2)))
                    continue;
                for (long long len = 0; len < (1 << m); ++len)
                {
                    if (len & L || len & S || len & a[i - 2] || (len & (len << 1)) || (len & (len << 2)))
                        continue;
                    f[L][S][i % 3] = max(f[L][S][i % 3], f[len][L][(i - 1) % 3] + Ss[S]);
                }
            }
        }
    for (long long L = 0; L < (1 << m); ++L)
        for (long long S = 0; S < (1 << m); ++S)
            ans = max(ans, f[L][S][(n - 1) % 3]);
    cout << ans << endl;
}