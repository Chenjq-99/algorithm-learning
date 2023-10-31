#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second

typedef pair<int, int> PII;

void solve() {
	string str;
	cin >> str;
	int n = str.length();
	int ans = n, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == '(') {
			cnt++;
		} else {
			if (cnt >= 1) {
				cnt--;
			} else {
				ans--;
			}
		}
	}	
	ans -= cnt;
	cout << ans << endl;
}

signed main() {
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int t = 1;
	// cin >> t;
	while (t--) solve();
	return 0;
}
