#include<bits/stdc++.h>
using namespace std;
long long l, r, n;
int main() {
	cin >> n >> l >> r;
	if(r==0){
	    for(int i=1;i<=n;i++)
	    cout<<0<<" ";
	    return 0;
	}
	long long k = 0;
	for (long long i = 1; i <= n; i++) {
		if ((n + 1 - i)*i == r) {
			k = i;
			break;
		}
	}
	if (!k) {
		cout << -1;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (i == k)
			cout << 1 << " ";
		else
			cout << 0 << " ";
	}
}