#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n;
int a[N], f[N], g[N];

void solve() {
	cin >> n;
	memset(f, 0x3f, sizeof f);
	memset(g, 0, sizeof g);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = n; i >= 0; i--) {
		int t = i + a[i] + 1;
		if (t <= n + 1) {
			int x = n - i - a[i]; 
			f[i] = min(f[i], x - g[t]);
		}
		g[i] = max(g[i + 1], n + 1 - i - f[i]);
		// cout << i << " " << f[i] << " " << g[i] << endl;
	}
	cout << f[0] << endl;
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}