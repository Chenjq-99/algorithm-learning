#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2010, M = 10010;

struct Edge {
	int x, y, w;
	bool operator<(const Edge& rhs) const {
		return w < rhs.w;
	}
} edges[M];

int n, m, p[N], cnt;

int find(int x) {
	return x == p[x] ? p[x] : p[x] = find(p[x]);
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}
	int res = 0;
	while (m--) {
		int op, x, y, w;
		cin >> op >> x >> y >> w;
		if (op == 1) {
			res += w;
			int px = find(x), py = find(y);
			p[px] = py;
		} else {
			edges[cnt++] = {x, y, w};
		}
	}
	sort(edges, edges + cnt);
	for (int i = 0; i < cnt; i++) {
		int x = edges[i].x, y = edges[i].y, w = edges[i].w;
		int px = find(x), py = find(y); {
			if (px != py) {
				res += w;
				p[px] = py;
			}
		}
	}
	cout << res << endl;
	return 0;
}