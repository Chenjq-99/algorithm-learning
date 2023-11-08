#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000010;

int n, m, p[N];

int find(int x) {
	return p[x] == x ? p[x] : p[x] = find(p[x]);
}
int main() {
	cin >> m >> n;
	for (int i = 0; i <= n * m; i++) {
		p[i] = i;
	}
	int x1, y1, x2, y2;
	while (cin >> x1 >> y1 >> x2 >> y2) {
		int u = x1 * n + y1, 
			v = x2 * n + y2;
		int pu = find(u), pv = find(v);
		p[pu] = pv;
	}
	int res = 0;
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i < m; i++) {
			int u = i * n + j,
				v = (i + 1) * n + j;
			int pu = find(u), pv = find(v);
			if (pu != pv) {
				p[pu] = pv;
				res += 1;
			}
		}
	}
	for (int j = 1; j < n; j++) {
		int u = 1 * n + j, v = 1 * n + j + 1;
		int pu = find(u), pv = find(v);
		if (pu != pv) {
			p[pu] = pv;
			res += 2;
		}
	}
	cout << res << endl;
	return 0;
}