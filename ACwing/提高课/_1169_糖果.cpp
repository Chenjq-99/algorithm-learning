#include <bits/stdc++.h>
using namespace std;

const int N = 100010, M = 300010;

int n, m;

int h[N], e[M], ne[M], w[M], idx;
long long dist[N];
int cnt[N];
bool st[N];

bool spfa() {

	memset(dist, -0x3f, sizeof dist);
	stack<int> stk;
	stk.push(0);
	dist[0] = 0;
	st[0] = true;

	while (stk.size()) {
		int x = stk.top();
		stk.pop();
		st[x] = false;
		for (int i = h[x]; ~i; i = ne[i]) {
			int y = e[i], v = w[i];
			if (dist[y] < dist[x] + v) {
				dist[y] = dist[x] + v;
				cnt[y] = cnt[x] + 1;
				if (cnt[y] > n + 1) return false;
				if (!st[y]) {
					stk.push(y);
					st[y] = true;
				}
			}
		}
	}
	return true;
}

void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	memset(h, -1, sizeof h);
	int op, a, b;
	while (m--) {
		cin >> op >> a >> b;
		switch (op) {
			case 1:
				add(a, b, 0), add(b, a, 0);
				break;
			case 2:
				add(a, b, 1);
				break;
			case 3:
				add(b, a, 0);
				break;
			case 4:
				add(b, a, 1);
				break;
			case 5:
				add(a, b, 0);
				break;
		}
	}
	for (int i = 1; i <= n; i++) add(0, i, 1);

	if (!spfa()) puts("-1");
	else {

		long long res = 0;
		for (int i = 1; i <= n; i++) res += dist[i];
		cout << res << endl;
	}

	return 0;
}
