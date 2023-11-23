#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

const int N = 1010;

int n, m;
int f[N], cnt[N];
double dist[N];
vector<pii> grid[N];
bool st[N];

bool check(int x) {

	memset(dist, 0, sizeof dist);
    memset(st, 0, sizeof st);
    memset(cnt, 0, sizeof cnt);

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
		st[i] = true;
	}

	while (q.size()) {
		int u = q.front();
		q.pop();
		st[u] = false;

		for (auto &[v, w] : grid[u]) {
			int d = dist[u] + f[u] - x * w;
			if (dist[v] < d) {
				dist[v] = d;
				cnt[v] = cnt[u] + 1;
				if (cnt[v] >= n) {
					return true;
				}
				if (!st[v]) {
					q.push(v);
					st[v] = true;
				}
			}
		}
	}
	return false;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> f[i];
	}
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		grid[u].emplace_back(v, w);
	}
	double l = 0, r = 1e6;
	while (r - l > 1e-4) {
		double mid = (l + r) / 2;
		if (check(mid)) l = mid;
		else r = mid;
	}

	cout << fixed << setprecision(2) << r << endl;

	return 0;
}
