#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second

typedef pair<int, int> PII;

const int N = 100010;

int n, m, path[N], cnt;

vector<int> g[N];

bool vis[N];

void solve() {
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(1); vis[1] = true;
	while (pq.size()) {
		int x = pq.top();
		pq.pop();
		path[cnt++] = x;
		for (auto& y : g[x]) {
			if (!vis[y]) {
				pq.push(y);
				vis[y] = true;
			}
		}
	}
	for (int i = 0; i < cnt; i++) {
		cout << path[i] << " ";
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
