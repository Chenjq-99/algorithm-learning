#include <bits/stdc++.h>
using namespace std;

int a[10];

inline void solve() {
	int n; cin >> n;
	long long ans= 1;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	a[0] += 1;
	for (int i = 0; i < n; i++) ans = ans * a[i];
	cout << ans << endl;	
}
int main() {
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}