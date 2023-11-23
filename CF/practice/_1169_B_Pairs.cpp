#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

const int M = 300010;
int n, m, a[M], b[M];

pii get_another(int x) {
	for (int i = 1; i < m; i++) {
		if (a[i] == x || b[i] == x) {
			continue;
		} else {
			return {a[i], b[i]};
		}
	}
	return {-1, -1};
}

bool check(int x, int y) {
	for (int i = 0; i < m; i++) {
		if (a[i] == x || b[i] == x) continue;
		else if (a[i] == y || b[i] == y) continue;
		else return false;
	}
	return true;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i];
	}
	int x[2] = {a[0], b[0]};
	bool ok = false;
	for (int i = 0; i < 2; i++) {
		pii y = get_another(x[i]);
		if (y.first == -1 && y.second == -1) {
			ok = true;
		} else {
			if (check(x[i], y.first)) {
				ok = true;
			}
			if (check(x[i], y.second)) {
				ok = true;
			}
		}
	}
	if (ok) puts("YES");
	else puts("NO");
	
}

signed main() {
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int t = 1;
	// cin >> t;
	while (t--) solve();
	return 0;
}
