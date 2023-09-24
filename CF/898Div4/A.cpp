#include <bits/stdc++.h>
#include <bits/stdc++.h>

using namespace std;

inline void solve() {
	string s;
	cin >> s;
	if (s[0] == 'a' || s[1] == 'b' || s[2] == 'c') puts("YES");
	else puts("NO");
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}