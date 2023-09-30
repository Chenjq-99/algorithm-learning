#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int n, q;

map<int, int> org, now;

int qmi(int a, int k, int p) {
	int res = 1;
	while (k) {
		if (k & 1) res = res * a % p;
		a = a * a % p;
		k >>= 1;
	}
	return res;
}

void solve() {
	cin >> n >> q;
	now.clear();
	int x = n;
	for (int i = 2; i <= x / i; i++) {
		while (x % i == 0) x /= i, ++now[i];
	}
	if (x > 1) ++now[x];
	x = n, org = now;
	while (q--) {
		int op; cin >> op;
		if (op == 2) now = org;
		else {
			int a; cin >> a;
			for (int i = 2; i <= a / i; i++) {
				while (a % i == 0) a /= i, ++now[i];
			}
			if (a > 1) ++now[a];
			int fn = 1, now_n = 1;
			for (auto v : now) fn *= (v.second + 1);
			for (auto v : now) (now_n *= qmi(v.first, v.second, fn)) %= fn;
			puts(now_n % fn ? "NO" : "YES");
		}
	}
	puts("");
}

signed main() {
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}