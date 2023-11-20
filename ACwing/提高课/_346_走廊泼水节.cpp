#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 6010;

struct Edge {
	int u, v, w;
	bool operator<(const Edge& rhs) const {
		return w < rhs.w;
	}
} edges[N];

int n, p[N], sz[N];

int find(int x) {
	return p[x] == x ? p[x] : p[x] = find(p[x]);
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) p[i] = i, sz[i] = 1;
	for (int i = 0; i < n; i++) cin >> edges[i].u >> edges[i].v >> edges[i].w;
	sort(edges, edges + n);
	int res = 0;
	for (int i = 0; i < n - 1; i++) {
		int u = edges[i].u, v = edges[i].v, w = edges[i].w;
		int fu = find(u), fv = find(v);
		if (fu != fv) {
			res += (sz[fv] * sz[fv] - 1) * (w + 1);
			p[fu] = fv;
			sz[fv] += sz[fu];
		}
	}
	cout << res << endl;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
	return 0;
}