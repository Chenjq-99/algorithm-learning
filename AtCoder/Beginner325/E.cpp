#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second

typedef pair<int, int> PII;

const int N = 1010;

int n, a, b, c;
int g[N][N], d1[N], d2[N], st[N];

void dijkstra(int S, int A, int B, int dist[]) {
   	memset(st, false, sizeof(st));
	dist[S] = 0;
	for (int i = 1; i <= n; i++) {
		int t = -1;
		for (int j = 1; j <= n; j++) {
			if (!st[j] && (t == -1 || dist[t] > dist[j])) {
				t = j;
			}
		}
		st[t] = true;
		for (int j = 1; j <= n; j++) {
			dist[j] = min(dist[j], dist[t] + g[t][j] * A + B);
		}
	}
}
signed main() {
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n >> a >> b >> c;
    // cout << a << " " << b << " " << c << endl;
   	for (int i = 1; i <= n; i++) {
   		for (int j = 1; j <= n; j++) {
   			cin >> g[i][j];
   		}
   	} 
   	memset(d1, 0x3f, sizeof(d1));
   	dijkstra(1, a, 0, d1);
   	memset(d2, 0x3f, sizeof(d2));
   	dijkstra(n, b, c, d2);
   	int ans = INT64_MAX;
   	for (int i = 1; i <= n; i++) {
   		ans = min(ans, d1[i] + d2[i]);
   	}
   	cout << ans << endl;
	return 0;
}