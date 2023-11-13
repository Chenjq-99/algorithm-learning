#include <iostream>
#include <vector>
#include <map>

void solve() {
	int n, m;
	long long ans = 0;
	std::cin >> n >> m;
	std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
	std::map<int, std::pair<int, long long>> mp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> a[i][j];
		}
	} 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int x = a[i][j];
			ans += (long long)mp[x].first * i - mp[x].second;
			mp[x].first += 1, mp[x].second += i;
		}
	}
	mp.clear();
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			int x = a[i][j];
			ans += (long long)mp[x].first * j - mp[x].second;
			mp[x].first += 1, mp[x].second += j;
		}
	}
	std::cout << ans << std::endl;
	return;
}

signed main() {
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int t = 1;
	// cin >> t;
	while (t--) solve();
	return 0;
}
