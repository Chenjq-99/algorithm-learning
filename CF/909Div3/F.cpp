#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int n, q, d[N];

void solve() {
	cin >> n >> q;
	for (int i = 0; i < q; i++) cin >> d[i];
	int cur = n - 1;
	for (int i = 1; i < n; i++)
		cout << i << " " << i + 1 << endl;
	for (int i = 0; i < q; i++) {
		if (cur == d[i]) {
			cout << -1 << " " << -1 << " " << -1 << endl;
		} else {
			cout << n << " " << cur << " " << d[i] << endl;
			cur = d[i];
		}
	}	
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
