// https://atcoder.jp/contests/dwacon5th-prelims/tasks/dwacon5th_prelims_b
#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 1010;

int n, k, m = 0;

int s[N], nums[N * N / 2];

signed main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		s[i] = s[i - 1] + x;
	}
	for (int l = 1; l <= n; l++) {
		for (int r = l; r <= n; r++) {
			nums[m++] = s[r] - s[l - 1];
		}
	}
	int ans = 0;
	for (int bit = 62; bit >= 0; bit--) {
		int cnt = 0, now = ans + (1LL << bit);
		for (int i = 0; i < m; i++) {
			if ((now & nums[i]) == now) {
				cnt++;
			}
		}
		if (cnt >= k) {
			ans = now;
		}
	}
	cout << ans << endl;
	return 0;
}