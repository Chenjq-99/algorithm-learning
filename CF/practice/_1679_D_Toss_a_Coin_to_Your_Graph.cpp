#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second

typedef pair<int, int> PII;

const int N = 200010, INF = 1e18 + 10;

vector<int> grid[N];

int n, m, k, limit, w[N], memo[N];
bool vis[N];

int dfs(int u) {
	if (vis[u]) {
		return INF;
	}
	if (memo[u] != -1) {
		return memo[u];
	}
	vis[u] = true;
	int res = 1;
	for (auto& v : grid[u]) {
		if (w[v] <= limit) {
			res = max(res, min(INF, dfs(v) + 1));
		}
	}
	vis[u] = false;
	return memo[u] = res;
}

bool check(int x) {
	limit = x;
	memset(memo, -1, sizeof memo);
	memset(vis, false, sizeof vis);
	for (int i = 1; i <= n; i++) {
		if (w[i] <= limit && memo[i] == -1) {
			dfs(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (memo[i] != -1 && memo[i] >= k) {
			return true;
		}
	}
	return false;
}

void solve() {
	cin >> n >> m >> k;
	int mx = 0, mn = INF;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
		mx = max(mx, w[i]);
		mn = min(mn, w[i]);
	}
	while (m--) {
		int a, b;
		cin >> a >> b;
		grid[a].push_back(b);
	}
	int ans = -1;
	if (check(mx)) {
		int l = mn, r = mx;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (check(mid)) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		ans = r;
	}
	cout << ans << endl;
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

// 992562455
// 114460923