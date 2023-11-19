#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, a[N], r[N];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	int minv = INT32_MAX, j = -1;
	for (int i = n - 1; i >= 0; i--) {
		r[i] = minv = min(minv, a[i]);
		if (i && a[i] < a[i - 1] && j == -1) {
			j = i;
		}
	}
	minv = INT32_MAX;
	bool ok = true;
	for (int i = 0; i < j; i++) {
		if (minv <= r[i]) {
			ok = false;
			break;
		}
		minv = min(minv, a[i]);
	}
	if (ok) cout << max(j, 0) << endl;
	else cout << -1 << endl;
}

signed main() {
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
