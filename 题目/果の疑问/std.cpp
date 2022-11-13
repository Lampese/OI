#include <bits/stdc++.h>
using namespace std;
#define MAXN 100
vector<unsigned long long> Hamel;
void insert(unsigned long long x) {
	for (auto b : Hamel) x = min(x, b ^ x);
	for (auto &b : Hamel) b = min(b, b ^ x);
	if (x) Hamel.push_back(x);
}
struct edge {
	int from, to, w;
} e[MAXN];
int f[MAXN], k;
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
int n, m, ans;
void kruskal() {
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= m; i++) {
		int f1 = find(e[i].from), f2 = find(e[i].to);
		if (f1 != f2) {
			insert(e[i].w);
			f[f2] = f1;
			++k;
			if (k == n - 1) return;
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> e[i].from >> e[i].to >> e[i].w;
	}
	sort(e + 1, e + m + 1, [](edge a, edge b)->bool {
		return a.w < b.w;
	});
	kruskal();
	if (k != n - 1) cout << "syxtql" << endl;
	else {
		int ans(0);
		for (auto s : Hamel) ans ^= s;
		cout << ans << endl;
	}
	return 0;
}