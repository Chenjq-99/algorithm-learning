#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

const int N = 510, M = N * N / 2;

struct Edge {
	int u, v;
	double w;
	bool operator< (const Edge &rhs) const {
		return w < rhs.w;
	}
} edges[M];

int n, m, k, p[N], cnt;
pair<int, int> node[N];

double get_dist(int i, int j) {
	double dx = node[i].first - node[j].first;
	double dy = node[i].second - node[j].second;
	return sqrt(dx * dx + dy * dy);
}

int find(int x) {
	return p[x] == x ? p[x] : p[x] = find(p[x]);
}

double kruskal() {
	sort(edges, edges + m);
	double res = 0;
	for (int i = 0; i < m; i++) {
		if (cnt <= k) break;
		int u = edges[i].u, v = edges[i].v;
		int fu = find(u), fv = find(v);
		if (fu == fv) continue;
		p[fu] = fv, cnt--;
		res = edges[i].w;
	}
	return res;
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> node[i].first >> node[i].second;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			edges[m++] = {i, j, get_dist(i, j)};
		}
	}
	for (int i = 0; i <= n; i++) p[i] = i;
	cnt = n;
	cout << fixed << setprecision(2) << kruskal() << endl;
	return 0;
}