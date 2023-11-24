#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

long long n, s, sum, a[N];

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] -= 1;
		sum += a[i];
	}
	s -= n;
	for (int i = 0; i < n; i++) {
		int mx = min(a[i], s);
		int mn = max(s - (sum - a[i]), 0LL);
		cout << a[i] - (mx - mn) << " ";
	}
	cout << endl;
	return 0;
}