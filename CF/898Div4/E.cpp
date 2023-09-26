#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
int n, x;
long long a[N], s[N];

inline bool check(long long h) {
	int i = upper_bound(a + 1, a + n + 1, h) - a - 1;
	return h * i - s[i] <= x; 
} 

void solve() {
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	long long l = a[1], r = a[n] + x;
	while (l < r) {
		long long mid = (l + r + 1) >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", r);
}
int main() {
	int t; cin >> t;
	while (t--) solve();
	return 0;
}