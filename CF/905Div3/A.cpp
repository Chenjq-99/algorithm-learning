#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second

typedef pair<int, int> PII;

void solve() {
	string s; cin >> s;
	int idx = 1, res = 0;
	for (int i = 0; i < 4; i++) {
		int t = s[i] - '0';
		if (t != 1 && t != 0) {
			if (idx == 0) {
				res += 10 - t + 1;
			} else {
				res += abs(idx - t) + 1;
			}
			
		} else {
			if (t == 1) {
				if (idx == 0) {
					res += 10;
				} else {
					res += idx;
				}
			}
			if (t == 0) {
				if (idx == 0) {
					res += 1;
				} else {
					res += 10 - idx + 1;
				}
			}
		}
		idx = t;
		// cout << "---" << res << endl;
	}
	cout << res << endl;
}

signed main() {
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
