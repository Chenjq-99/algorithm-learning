#include <bits/stdc++.h>
using namespace std;

const int N = 1010, M = 100010;

int n, m, S, T;

int h[N], e[M], w[M], ne[M], idx;

int dist[N][2], cnt[N][2], st[N][2];

struct Node {
	int id, type, dist;
	bool operator> (const Node& node) const {
		return dist > node.dist;
	}
};

void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}


void init() {
	memset(dist, 0x3f, sizeof(dist));
	memset(cnt, 0, sizeof(cnt));
	memset(st, false, sizeof(st));
}

int dijkstra() {
	init();
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	dist[S][0] = 0, cnt[S][0] = 1;
	pq.push(Node{S, 0, 0});
	while (pq.size()) {
		auto t = pq.top();
		pq.pop();
		int id = t.id, type = t.type, distance = t.dist;
		if (st[id][type]) continue;
		else st[id][type] = true;
		for (int i = h[id]; ~i; i = ne[i]) {
			int j = e[i];
			if (distance + w[i] < dist[j][0]) {
				dist[j][1] = dist[j][0];
				cnt[j][1] = cnt[j][0];
				pq.push(Node{j, 1, dist[j][1]});
				dist[j][0] = distance + w[i]; 
				cnt[j][0] = cnt[id][type];
				pq.push(Node{j, 0, dist[j][0]});
			} else if (distance + w[i] == dist[j][0]) {
				cnt[j][0] += cnt[id][type];
			} else if (distance + w[i] < dist[j][1]) {
				dist[j][1] = distance + w[i]; 
				cnt[j][1] = cnt[id][type];
				pq.push(Node{j, 1, dist[j][1]});
			} else if (distance + w[i] == dist[j][1]) {
				cnt[j][1] += cnt[id][type];
			}
		}
	}
	int res = cnt[T][0];
	if (dist[T][1] == dist[T][0] + 1) res += cnt[T][1];
	return res;
}

void solve() {
	cin >> n >> m;
	memset(h, -1, sizeof(h));
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	cin >> S >> T;
	cout << dijkstra() << endl;

	return;	
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}