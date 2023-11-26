#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

void solve() {
	int n; cin >> n;
	vector<int> ops;
	int mx = 0, mn = 1e9;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		mx = max(mx, x);
		mn = min(mn, x);
	}
	int res = 0, m = 2;
	while (mx != mn) {
		int x = mx / 2, y = mn / 2;
		int a = (mx + 1) / 2, b = (mn + 1) / 2;
		if (x - y <= a - b) {
			mx = x, mn = y;
			ops.push_back(0);
		}
		else {
			mx = a, mn = b;
			ops.push_back(1);
		}
		res++;
	}
	cout << res << endl;
	if (res <= n) {
		for (auto &op : ops) cout << op << " ";
		if (ops.size()) cout << endl;		
	}
}

int main() {
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
