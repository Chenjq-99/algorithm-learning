#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
int n, k;
char str[N];

inline void solve() {
	scanf("%d%d%s", &n, &k, str);
	vector<int> ids;
	for (int i = 0; i < n; i++)
		if (str[i] == 'B')
			ids.push_back(i);
	int id = -1, res = 0;
	while (ids.size() &&id < ids.back()) {
		auto it = upper_bound(ids.begin(), ids.end(), id);
		res++, id = *it + k - 1;
	}
	cout << res << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();
	return 0;
}