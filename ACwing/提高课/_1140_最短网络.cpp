#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int n, g[N][N], dist[N];
bool st[N];

int prime() {
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int t = -1;
		for (int j = 1; j <= n; j++) {
			if (!st[j] && (t == -1 || dist[j] < dist[t])) {
				t = j;
			}
		}
		res += dist[t];
		st[t] = true;
		for (int j = 1; j <= n; j++) {
			dist[j] = min(dist[j], g[t][j]);
		}
	}
	return res;
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> g[i][j];
		}
	}
	cout << prime() << endl;
	return 0;
}