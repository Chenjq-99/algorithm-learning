#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 110;
int n, k;
int a[N];

void solve() {
	cin >> n >> k;
	bool find = false;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == k) find = true;
	}
	if (!find) puts("NO");
	else puts("YES");
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}