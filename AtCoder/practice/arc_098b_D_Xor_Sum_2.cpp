// https://atcoder.jp/contests/abc098/tasks/arc098_b
#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n, a[N];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	int or_ = 0;
	long long ans = 0;
	for (int r = 0, l = 0; r < n; r++) {
		while (or_ & a[r]) {
			or_ ^= a[l++];
		}
		or_ |= a[r];
		ans = ans + r - l + 1;
	}	
	cout << ans << endl;
	return 0;
}