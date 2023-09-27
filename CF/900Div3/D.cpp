#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 200010;

int n, k;
int l[N], r[N], c[N];
string s;

void solve() {
	cin >> n >> k >> s;
	for (int i = 0; i < k; i++) cin >> l[i];
	for (int i = 0; i < k; i++) cin >> r[i];
	int q;
	cin >> q;
	memset(c, 0, sizeof c);
	unordered_map<int, int> mp;
	while (q--) {
		int x;
		cin >> x;
		int i = upper_bound(l, l + k, x) - l - 1;
		int a = min(x, l[i] + r[i] - x), b = max(x, l[i] + r[i] - x);
		c[a] += 1, c[b + 1] -= 1;
		mp[l[i]] = r[i]; 
	}
	for (int i = 1; i <= n; i++) c[i] += c[i - 1];
	for (int i = 1; i <= n; i++) {
		if (mp.count(i)) {
			int j = mp[i];
			for (int t = i; t <= j; t++) {
				if (c[t] & 1) {
					cout << s[i + j - t - 1];
				} else {
					cout << s[t - 1];
				}
			}
			i = j;
		} else {
			cout << s[i - 1];
		}
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}