#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n, k;
int a[N], h[N];

void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) scanf("%d", &h[i]);
	int sum = 0, ans = 0;
	for (int r = 0, l = 0; r < n; r++) {
		if (r == 0 || h[r - 1] % h [r] != 0) l = r, sum = 0;
		if (a[r] <= k) sum += a[r];
		else {
			l = r + 1;
			sum = 0;
			continue;
		}
		while (l < r && sum > k) {
			sum -= a[l++];
		} 
		ans = max(ans, r - l + 1);
	}
	printf("%d\n", ans);
}
int main() {
	int t; scanf("%d", &t);
	while (t--) solve();
	return 0;
}
