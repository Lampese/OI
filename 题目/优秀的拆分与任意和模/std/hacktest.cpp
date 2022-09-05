//Code by do_while_true
#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
#define re register
#define int long long
inline int Max(int x, int y) { return x > y ? x : y; }
inline int Min(int x, int y) { return x < y ? x : y; }
inline int Abs(int x) { return x < 0 ? ~x + 1 : x; }
inline int read() {
	int r = 0; bool w = 0; char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') w = 1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		r = (r << 3) + (r << 1) + (ch ^ 48);
		ch = getchar();
	}
	return w ? ~r + 1 : r;
}
#undef int
const int N = 40000000;
struct Q {
	int k, id;
}a[N];
ll ans;
bool cmp(Q x, Q y) { return x.k < y.k; }
int q, m,n;
signed main() {
	q = read(); m = read();n = read();
	for(int i = 1; i <= q; ++i)
		a[i].id = i, a[i].k = read();
	std::sort(a + 1, a + q + 1, cmp);
	ll now = n; int cnt = 0;
	for(int i = 1; i <= q; ++i) {
		while(cnt < a[i].k) ++cnt, now = (now * n) % m;
		ans = (ans + now) % m;
	}
	printf("%lld\n", ans);
	return 0;
}