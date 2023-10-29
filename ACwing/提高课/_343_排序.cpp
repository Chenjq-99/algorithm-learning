#include <bits/stdc++.h>
using namespace std;

const int N = 30;

int n, m;
int g[N][N], d[N][N];
bool st[N];

void floyd() {
	memcpy(d, g, sizeof g);

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				d[i][j] |= d[i][k] && d[k][j];
			}
		}
	}
}

int check() {

	for (int i = 0; i < n; i++) {
		if (d[i][i]) {
			return 2;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (!d[i][j] && !d[j][i]) {
				return 0;
			}
		}
	}
	return 1;
}

char get_min() {
	for (int i = 0; i < n; i++) {
		if (!st[i]) {
			bool ok = true;
			for (int j = 0; j < n; j++) {
				if (!st[j] && d[j][i]) {
					ok = false;
				}
			}
			if (ok) {
				st[i] = true;
				return 'A' + i;
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	while (cin >> n >> m, n || m) {
		memset(g, 0, sizeof g);
		memset(st, false, sizeof st);
		int type = 0, t = 0;
		for (int i = 1; i <= m; i++) {
			char s[5];
			cin >> s;
			int a = s[0] - 'A', b = s[2] - 'A';
			if (!type) {
				g[a][b] = 1;
				floyd();
				type = check();
				if (type) {
					t = i;
				}
			}
		}
		if (!type) {
			cout << "Sorted sequence cannot be determined." << endl;
		} else if (type == 2) {
			cout << "Inconsistency found after " << t << " relations." << endl;
		} else {
			cout << "Sorted sequence determined after " << t << " relations: ";
			for (int i = 0; i < n; i++) {
				cout << get_min();
			}
			cout << "." << endl;
		}
	}
	return 0;
}
