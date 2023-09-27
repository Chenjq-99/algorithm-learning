#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 200010;

int n;
LL a[N];

void solve() {
	cin >> n;
	a[0] = 1;
	for (int i = 1; i < n; i++) {
		a[i] = a[i - 1] + 3;
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}