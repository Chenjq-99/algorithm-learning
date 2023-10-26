#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second

typedef pair<int, int> PII;

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	int t = n - k;
	map<char, int> mp;
	for (auto& ch : s) {
		mp[ch]++;
	}
	int cnt = 0;
	for (auto& [k, v] : mp) {
		if (v & 1) {
			cnt++;
		}
	}
	if (t & 1) {
		if (cnt - 1 <= k) {
			puts("YES");
		} else {
			puts("NO");
		}
	} else {
		if (cnt <= k) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
}

signed main() {
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
