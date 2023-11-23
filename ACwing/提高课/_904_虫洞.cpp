#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

const int N = 510, M = 5210;

int n, m1, m2;
int cnt[N], dist[N];
bool st[N];	

void solve() {

	vector<pii> grid[N];
	queue<int> q;
	memset(cnt, 0, sizeof cnt);
	memset(dist, 0, sizeof dist);
	memset(st, false, sizeof st);

	cin >> n >> m1 >> m2;
	while (m1--) {
		int u, v, w;
		cin >> u >> v >> w;
		grid[u].emplace_back(v, w);
		grid[v].emplace_back(u, w);
	}
	while (m2--) {
		int u, v, w;
		cin >> u >> v >> w;
		grid[u].emplace_back(v, -w);
	}

	for (int i = 1; i <= n; i++) {
		q.push(i);
		st[i] = true;
	}

	bool ok = false;
	while (q.size()) {
		int u = q.front();
		q.pop();
		st[u] = false;
		for (auto &[v, w] : grid[u]) {
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				cnt[v] = cnt[u] + 1;
				if (cnt[v] >= n) {
					ok = true;
					break;
				}
				if (!st[v]) {
					q.push(v);
					st[v] = true;
				}
			}
		}
	}
	if (ok) {
		puts("YES");
	} else {
		puts("NO");
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
	return 0;	
}