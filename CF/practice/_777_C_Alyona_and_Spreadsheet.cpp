#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second

typedef pair<int, int> PII;

void solve() {
	int n, m, k;
	cin >> n >> m;
	int a[n + 5][m + 5], f[n + 5], g[n + 5];
	memset(g, 0x3f, sizeof g);
	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (int j = 1; j <= m; j++) {
		int tmp[m + 5];
		for (int i = 1; i <= n; i++) {
			tmp[i] = i;
		}
		f[1] = tmp[1];
		for (int i = 2; i <= n; i++) {
			if (a[i][j] >= a[i - 1][j]) {
				tmp[i] = min(tmp[i], tmp[i - 1]);
			}
			f[i] = min(f[i], tmp[i]);
		}
	}
	for (int i = n; i >= 1; i--) {
		g[i] = min(g[i + 1], f[i]); 
	}
	cin >> k;
	while (k--) {
		int l, r; cin >> l >> r;
		if (g[r] <= l) {
			puts("Yes");
		} else {
			puts("No");
		}
	}
}

signed main() {
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int t = 1;
	// cin >> t;
	while (t--) solve();
	return 0;
}
