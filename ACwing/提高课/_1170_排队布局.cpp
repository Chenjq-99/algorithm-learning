#include <bits/stdc++.h>
using namespace std;

const int N = 1010, M = 20010, INF = 0x3f3f3f3f;

int n, m1, m2;
int h[N], e[M], w[M], ne[M], idx;
int dist[N], cnt[N];
bool st[N];

void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa(int m) {
	memset(dist, 0x3f, sizeof dist);
	memset(st, false, sizeof st);
	memset(cnt, 0, sizeof cnt);

	queue<int> q;
	for (int i = 1; i <= m; i++) {
		q.push(i);
		dist[i] = 0, st[i] = true;
	}
	while (q.size()) {
		int t = q.front();
		q.pop();
		st[t] = false;

		for (int i = h[t]; ~i; i = ne[i]) {
			int j = e[i];
			if (dist[j] > dist[t] + w[i]) {
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t] + 1;
				if (cnt[j] >= n)
					return false;
				if (!st[j]) {
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m1 >> m2;

	memset(h, -1, sizeof h);
	
    for (int i = 1; i < n; i ++ ) add(i + 1, i, 0);
    
	while (m1--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a > b) swap(a, b);
		add(a, b, c);
	}

	while (m2--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a > b) swap(a, b);
		add(b, a, -c);
	}

	if (!spfa(n)) puts("-1");
	else {
		spfa(1);
		if (dist[n] == INF) puts("-2");
		else cout << dist[n] << endl;
	}
	return 0;
}