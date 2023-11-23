#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

using LL = long long;
using pii = pair<int, int>;

const int N = 510, M = 10010;

int n, m;
int p[N], dist1[N][N], dist2[N][N];
vector<pii> g[N];

struct Edge {
	int u, v, w;
	bool flag = false;
	bool operator<(const Edge& rhs) const {
		return w < rhs.w;
	}
} edges[M];

int find(int x) {
	return p[x] == x ? p[x] : p[x] = find(p[x]);
}
void dfs(int u, int fu, int maxv, int maxvv, int d1[], int d2[]) {
	d1[u] = maxv, d2[u] = maxvv;
	for (auto &[v, w] : g[u]) {
		if (v == fu) continue;
		if (w > maxv) {
			maxvv = maxv, maxv = w;
		} else if (w < maxv && w > maxvv) {
			maxvv == w;
		}
		dfs(v, u, maxv, maxvv, d1, d2);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		p[i] = i;
	}

	for (int i = 0; i < m; i++) {
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
	}

	sort(edges, edges + m);
	LL sum = 0;
	for (int i = 0; i < m; i++) {
		int u = edges[i].u, v = edges[i].v, w = edges[i].w;
		int fu = find(u), fv = find(v);
		if (fu != fv) {
			edges[i].flag = true;
			p[fu] = fv;
			sum += w;
			g[u].emplace_back(v, w);
			g[v].emplace_back(u, w);
		}
	}

	for (int i = 1; i <= n; i++) {
		dfs(i, -1, 0, 0, dist1[i], dist2[i]);
	}

	LL res = 1e18;
	for (int i = 0; i < m; i++) {
		if (!edges[i].flag) {
			int u = edges[i].u, v = edges[i].v, w = edges[i].w;
			if (w > dist1[u][v]) {
				res = min(res, sum + w - dist1[u][v]);
			} else if (w > dist2[u][v]) {
				res = min(res, sum + w - dist2[u][v]);
			}
		}
	}
	cout << res << endl;
	return 0;
}