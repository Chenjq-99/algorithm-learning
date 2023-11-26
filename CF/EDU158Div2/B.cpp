#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
long long n, c[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	long long res = 0;
	for (int i = 1; i <= n; i++) 
		if (c[i] > c[i - 1])
			res += c[i] - c[i - 1];
	cout << res - 1 << endl;
}

signed main() {
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
