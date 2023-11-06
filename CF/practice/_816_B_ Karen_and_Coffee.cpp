#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second

typedef pair<int, int> PII;

const int N = 200010;

int n, k, q, mx, b[N];

void calc() {
	for (int i = 1; i <= mx; i++) {
		b[i] += b[i - 1];
	}
	return;
}

void solve() {
	cin >> n >> k >> q;
	while (n--) {
		int l, r;
		cin >> l >> r;
		b[l]++, b[r + 1]--;
		mx = max(mx, r + 1);
	}
	calc();
	for (int i = 1; i <= mx; i++) {
		b[i] = b[i] >= k;
	}
	calc();
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << b[r] - b[l - 1] << endl;
	}
	return;
}

signed main() {
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int t = 1;
	// cin >> t;
	while (t--) solve();
	return 0;
}
