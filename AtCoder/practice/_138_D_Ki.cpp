#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n, q;
vector<int> adj[N];
int values[N];

void dfs(int x, int fa) {
	for (auto &y : adj[x]) {
		if (y == fa) continue;
		values[y] += values[x];
		dfs(y, x);
	}
}
int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	while (q--) {
		int x, v;
		scanf("%d%d", &x, &v);
		values[x] += v;
	}
	dfs(1, -1);
	for (int i = 1; i <= n; i++) {
		printf("%d ", values[i]);
	}
	printf("\n");
	return 0;
}