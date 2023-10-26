#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second

typedef pair<int, int> PII;

void solve() {
	int n, k;
	cin >> n >> k;
	int ans = k, even_cnt = 0;
	for (int i= 0; i < n; i++) {
		int x; cin >> x;
		if (x % 2 == 0) even_cnt++;
		if (x % k == 0) ans = 0;
		ans = min(ans, k - x % k);
	} 
	if (k == 4) {
		if (even_cnt >= 2) {
			ans = min(ans, 0LL);
		} else if (even_cnt == 1) {
			ans = min(ans, 1LL);
		} else {
			ans = min(ans, 2LL);
		}
	}
	cout << ans << endl;
}

signed main() {
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
