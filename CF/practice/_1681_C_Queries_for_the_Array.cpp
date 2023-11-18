#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second

typedef pair<int, int> PII;

void solve() {
	string str;
	cin >> str;
	bool ok = true;
	int cnt = 0, sortedLen = 0, unsortedLen = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '+') {
			cnt++;
		} else if (str[i] == '-') {
			cnt--;
			if (cnt < sortedLen) {
				sortedLen = cnt;
			}
			if (cnt < unsortedLen) {
				unsortedLen = 0;
			}
		} else if (str[i] == '1') {
			if (unsortedLen != 0) {
				ok = false;
				break;
			}
			sortedLen = cnt;
		} else if (str[i] == '0') {
			if (cnt < 2 || sortedLen == cnt) {
				ok = false;
				break;
			}
			if (!unsortedLen) {
				unsortedLen = cnt;
			}
		}
	}
	if (ok) {puts("YES");}
	else {puts("NO");}
}

signed main() {
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
