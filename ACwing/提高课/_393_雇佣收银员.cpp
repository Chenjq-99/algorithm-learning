#include <bits/stdc++.h>
using namespace std;

const int N = 30, M = 100;

int n;
int h[N], e[M], ne[M], w[M], idx;
int dist[N], cnt[N];
int r[N], nums[N];
bool st[N];

void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void build(int c) {
	memset(h, -1, sizeof h); idx = 0;
	add(0, 24, c), add(24, 0, -c);
	for (int i = 1; i <= 24; i++) add(i - 1, i, 0);
	for (int i = 1; i <= 24; i++) add(i, i - 1, -nums[i]);
	for (int i = 1; i <= 7; i++) add(i + 16, i, r[i] - c);
	for (int i = 8; i <= 24; i++) add(i - 8, i, r[i]);
}

bool spfa(int c) {
	build(c);

	memset(st, false, sizeof st);
	memset(cnt, 0, sizeof cnt);
	memset(dist, -0x3f, sizeof dist);

	queue<int> q;
	q.push(0);
	dist[0] = 0, st[0] = true;

	while (q.size()) {
		int t = q.front(); 
		q.pop(); st[t] = false;
		for (int i = h[t]; ~i; i = ne[i]) {
			int j = e[i];
			if (dist[j] < dist[t] + w[i]) {
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t] + 1;
				if (cnt[j] >= 25) return false;
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

	int T; cin >> T;

	while (T--) {
		for (int i = 1; i <= 24; i++) cin >> r[i];
		cin >> n;
		memset(nums, 0, sizeof nums);
		for (int i = 0; i < n; i++) {
			int t; cin >> t;
			nums[t + 1]++;
		}
		bool ok = false;
		for (int i = 0; i <= 1000; i++) {
			if (spfa(i)) {
				cout << i << endl;
				ok = true;
				break;
			}
		}
		if (!ok) cout << "No Solution" << endl;
	}
	return 0;
}