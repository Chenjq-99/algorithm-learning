#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL n, x, k;

LL p2(LL x, LL h) {
	while (x <= n && h) {
		x *= 2, h--;
	}
	return x;
}

LL calc(LL x, LL h) {
	LL l = p2(x, h), r = p2(x + 1, h) - 1;
	if (l > n) return 0;
	return min(r, n) - l + 1;
}
void solve() {
	cin >> n >> x >> k;
	LL ans = 0, last = -1;
	while (x >= 1 && k >= 0) {
		ans += calc(x, k);
		if (last != -1 && k >= 1) ans -= calc(last, k - 1);
		last = x, x = x / 2, k = k - 1;
	}
	cout << ans << endl;
}
int main() {
	int t; cin >> t;
	while (t--) solve();
	return 0;
}