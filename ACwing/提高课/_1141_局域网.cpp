#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110, M = 210;

struct Edge {
	int x, y, w;
	bool operator<(const Edge& rhs) const {
		return w < rhs.w;
	}
} edges[M];

int n, m, p[N];

int find(int x) {
	return p[x] == x ? p[x] : p[x] = find(p[x]);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}

	for (int i = 0; i < m; i++) {
		cin >> edges[i].x >> edges[i].y >> edges[i].w;
	}

	sort(edges, edges + m);

	int res = 0;
	for (int i = 0; i < m; i++) {
		int px = find(edges[i].x), py = find(edges[i].y);
		if (px == py) {
			res += edges[i].w;
		} else {
			p[px] = py;
		}
	}
	cout << res << endl;
	return 0;
}

