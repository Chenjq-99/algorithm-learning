#include <iostream>
#include <algorithm>
using namespace std;

const int N = 310, M = 8010;

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

int kruskal() {
	int res = 0;
	for (int i = 0; i < m; i++) {
		int x = edges[i].x, y = edges[i].y, w = edges[i].w;
		int px = find(x), py = find(y);
		if (px != py) {
			p[px] = py;
			res = w;
		}
	}
	return res;
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

	cout << kruskal << endl;
	return 0;
}