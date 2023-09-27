#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

void solve() {
	LL n, k, x;
	cin >> n >> k >> x;
	LL minv = k + (k - 1) * k / 2;
	LL maxv = k * n - (k - 1) * k / 2;
	if (x >= minv && x <= maxv) puts("YES");
	else puts("No");
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}