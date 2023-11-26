#include <bits/stdc++.h>

using namespace std;

int n, x;

void solve() {
	cin >> n >> x;
	int res = 0, last = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		res = max(res, a - last);
		last = a;
	}
	res = max(res, 2 * (x - last));
	cout << res << endl;
	return;
}

signed main() {
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
