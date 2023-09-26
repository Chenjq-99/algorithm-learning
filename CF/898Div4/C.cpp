#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int res = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			char ch; cin >> ch;
			if (ch == 'X') {
				int x, y;
				if (i < 5) x = i + 1;
				else x = 10 - i;
				if (j < 5) y = j + 1;
				else y = 10 - j;
				res += min(x, y);
			}
		}
	}
	cout << res << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();
	return 0;
}