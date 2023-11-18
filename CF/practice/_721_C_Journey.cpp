#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second

typedef pair<int, int> PII;

const int N = 5010, M = 5010;

int n, m, T;

struct Edge {
	int u, v, w;
} edges[M];

int f[N][N], from[N][N];

void solve() {
	cin >> n >> m >> T;
	for (int i = 0; i < m; i++) {
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
	}
	memset(f, 0x3f, sizeof f);
	f[1][0] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int u = edges[j].u, v = edges[j].v, w = edges[j].w;
			if (f[v][i] > f[u][i - 1] + w) {
				f[v][i] = f[u][i - 1] + w;
				from[v][i] = u;
			}
		}
	}
	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (f[n][i] <= T) {
			ans = i;
			break;
		}
	}
	cout << ans + 1 << endl;
	vector<int> path = {n};
	for (int i = ans, x = n; i > 0; i--) {
		path.push_back(from[x][i]);
		x = from[x][i];
	}
	reverse(path.begin(), path.end());
	for (auto& x : path) {
		cout << x << " ";
	}
	cout << endl;
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
