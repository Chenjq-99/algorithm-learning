#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second

typedef pair<int, int> PII;

void solve() {
	map<double, int> mp;
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		ans += mp[(double)x - log2(x)]++;
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
