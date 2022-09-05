#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll Mod = 1000000007;
ll n, k;
struct matrix
{
    ll m[105][105];
} a;
matrix x(matrix a, matrix b)
{
    matrix t;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            t.m[i][j] = 0;
            for (int k = 0; k < n; ++k)
                t.m[i][j] = (t.m[i][j] + a.m[i][k] * b.m[k][j]) % Mod;
        }
    return t;
}
matrix fast_m(matrix a, ll k)
{
    matrix ret = a, b = a;
    --k;
    while (k)
    {
        if (k & 1)
            ret = x(b, ret);
        b = x(b, b);
        k >>= 1;
    }
    return ret;
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a.m[i][j];
    a = fast_m(a, k);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a.m[i][j] << " ";
        cout << endl;
    }
}