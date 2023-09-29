#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second

typedef pair<int, int> PII;

const int N = 200010;

int n, a[N], s[35][N];

bool check(int l, int r, int k) {
	int res = 0;
	for (int bit = 0; bit <= 30; bit++) {
		if (s[bit][r] - s[bit][l - 1] == r - l + 1)
			res += (1LL << bit);
	}
	return res >= k;
}

void solve() {
	cin >> n;
	for (int i = 0; i <= 30;i++){
		for (int j = 1; j <= n;j++) {
			s[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int bit = 0; bit <= 30; bit++) {
			if (a[i] >> bit & 1) s[bit][i] = 1;
			s[bit][i] += s[bit][i - 1];
		}
	}
	int q; cin >> q;
	while (q--) {
		int l, k; cin >> l >> k;
		int L = l, r = n;
		while (l < r) {
			int mid = (l + r + 1) >> 1;
			if (check(L, mid, k)) l = mid;
			else r = mid - 1;
		}
		cout << (check(L, r, k) ? r : -1) << " ";
	}
	cout << endl;
}

signed main() {
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}