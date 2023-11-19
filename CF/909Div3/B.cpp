#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second

typedef pair<int, int> PII;

const int N = 150010, INF = INT64_MAX;

int n, s[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] += s[i - 1];
	}
	int ans = 0;
	for (int k = 1; k < n; k++) {
		int minv = INF, maxv = 0;
		if (n % k == 0) {
			for (int i = k; i <= n; i += k) {
				int t = s[i] - s[i - k];
				minv = min(minv, t);
				maxv = max(maxv, t);
			}
			ans = max(ans, maxv - minv);
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
