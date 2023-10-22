#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second

typedef pair<int, int> PII;

const int N = 1010, M = N * N;

int n, m;

char g[N][N];

int p[M], sz;

int find(int x) {
	return x == p[x] ? p[x] : p[x] = find(p[x]);
}

signed main() {
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n * m; i++) {
    	p[i] = i;
    }
    for (int i = 0; i < n; i++) {
    	cin >> g[i];
    	for (int j = 0; j < m; j++) {
    		if (g[i][j] == '#') {
    			sz++;
    		}
    	}
    }

    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, 
    	dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int x = 0; x < n; x++) {
    	for (int y = 0; y < m; y++) {
    		if (g[x][y] != '#') {
    			continue;
    		}
    		for (int i = 0; i < 8; i++) {
    			int nx = x + dx[i], ny = y + dy[i];
    			if (nx < 0 || nx >= n || ny < 0 || ny >= m || g[nx][ny] != '#') {
    				continue;
    			}
    			int a = x * m + y, b = nx * m + ny;
    			int fa = find(a), fb = find(b);
    			if (fa != fb) {
    				p[fa] = fb;
    				sz--;
    			}
    		}
    	}
    }
    cout << sz << endl;
	return 0;
}