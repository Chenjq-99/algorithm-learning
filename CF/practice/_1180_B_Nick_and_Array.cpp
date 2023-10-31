#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int n, w[N];

void solve() {
	using pii = pair<int, int>;
	cin >> n;
	vector<pii> x, y;
	for (int i = 0; i < n; i++) {
		cin >> w[i];
		if (w[i] >= 0) {
			w[i] = -w[i] - 1;
		}
	}
	if (n & 1) {
		int id = min_element(w, w + n) - w;
		w[id] = -w[id] - 1;
	}
	for (int i = 0; i < n; i++) {
		cout << w[i] << " ";
	}
	cout << endl;
}

int main() {
	int t = 1;
	while (t--) {
		solve();
	}
	return 0;
}