#include <bits/stdc++.h>

#define int long long

const int N = 200010;

using pii = std::pair<int, int>;

int n;
pii a[N];

void solve() {
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i].first;
	}
	for (int i = 0; i < n; i++) {
		std::cin >> a[i].second;
	}
	std::sort(a, a + n);
	int sum = 0, res = 0x3f3f3f3f;
	for (int i = n - 1; i >= 0; i--) {
		res = std::min(res, std::max(a[i].first, sum));
		sum += a[i].second;
	}
	res = std::min(res, sum);
	std::cout << res << std::endl;
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t; std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}