#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n, a, b, entry_node = -1;
vector<int> adj[N];
vector<bool> vis(N);

bool dfs1(int u, int fa) {
	vis[u] = true;
	for (auto& v : adj[u]) {
		if (v != fa && vis[v]) {
			entry_node = v;
			return true;
		} 
		if (v != fa && !vis[v]) {
			if (dfs1(v, u)) {
				return true;
			}
		}
	}
	return false;
}

int dfs2(int u) {
	// cout << u << endl;
	if (u == entry_node) return 0;
	int res = 0x3f3f3f3f;
	vis[u] = true;
	for (auto& v : adj[u]) {
		if (!vis[v])
			res = min(res, dfs2(v) + 1);
	}
	return res;
}

void solve() {
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 0; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1(b, -1);
	// cout << entry_node << endl;
	vis.assign(n + 1, false);
	int da = dfs2(a);
	vis.assign(n + 1, false);
	int db = dfs2(b);
	// cout << da << " " << db << endl;
	if (da <= db) puts("NO");
	else puts("YES");
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		vis[i] = false;
	}
}
int main() {
	int t; scanf("%d", &t);
	while (t--) solve();
	return 0;
}

