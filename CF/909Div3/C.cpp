#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second

typedef pair<int, int> PII;

const int N = 200010;
int n, a[N], f[N];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	memset(f, -0x3f, sizeof f);
	f[0] = a[0];
	int ans = f[0];
	for (int i = 1; i < n; i++) {
		f[i] = a[i];
		if ((a[i - 1] & 1) != (a[i] & 1)) {
			f[i] = max(f[i], f[i - 1] + a[i]);
		}
		ans = max(ans, f[i]);
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
