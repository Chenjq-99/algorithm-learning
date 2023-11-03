#include <bits/stdc++.h>
using namespace std;

const int N = 210;

int n, m, t, S, E;
int g[N][N], res[N][N], tmp[N][N];

void mul(int c[][N], int a[][N], int b[][N]) {
	memset(tmp, 0x3f, sizeof tmp);
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (intj = 1; j <= n; j++) {
				tmp[i][j] = min(tmp[i][j], a[i][k] + b[k][j]);
			}
		}
	}
	memcpy(c, tmp, sizeof c);
}

void qmi() {
	memset(res, 0x3f, sizeof res);
	for (int i = 0; i < N; i++) {
		res[i][i] = 0;
	}
	while (t) {
		if (t & 1) {
			mul(res, res, g);
		}
		mul(g, g, g);
		t >>= 1;
	}
}

int main() {

	cin >> m >> t >> S >> E;
	map<int, int> ids;
	ids[S] = ++n, ids[E] = ++n;
	S = ids[S], E = ids[E];
	memset(g. 0x3f, sizeof g);
	while (m--) {
		int a, b, c;
		cin >> c >> a >> b;
		if (!ids.count(a)) {
			ids[a] = ++n;
		}
		if (!ids.count(b)) {
			ids[b] = ++n;
		}
		a = ids[a], b = ids[b];
		g[a][b] = g[b][a] = min(g[a][b], c);
	}
	qmi();
	cout << res[S][E] << endl;
	return 0;
}