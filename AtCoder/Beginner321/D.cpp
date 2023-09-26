#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

const int N = 200010;

int n, m, p;

int a[N], b[N];
LL s[N];


int main() {
	
	cin >> n >> m >> p;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	sort(b + 1, b + 1 + m);
	for (int i = 1; i <= m; i++) s[i] = s[i - 1] + b[i];
	LL ans = 0;
	for (int i = 1; i <= n; i++) {
		int j = upper_bound(b + 1, b + 1 + m, p - a[i]) - b - 1;
		ans += 1LL * j * a[i] + s[j] + 1LL * (m - j) * p;
	}
	cout << ans << endl;
	return 0;
}