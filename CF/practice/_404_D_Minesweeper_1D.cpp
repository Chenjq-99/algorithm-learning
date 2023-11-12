#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second

typedef pair<int, int> PII;

const int N = 1000010, MOD = 1e9 + 7;

int n, memo[N][2][3];
char str[N];

int dfs(int u, int prevType, int type) {
	if (u == n) {
		if (type == 1) {
			return 0;
		}
		return 1;
	}
	if (memo[u][prevType][type] != -1) {
		return memo[u][prevType][type];
	}
	int res = 0;
	if (str[u] == '?') {
		if (type == 1) {
			res = (res + dfs(u + 1, 1, 2)) % MOD;
		} else {
			if (prevType == 0) {
				res = (res + dfs(u + 1, 0, 0)) % MOD;
			}
			if (prevType == 1) {
				res = (res + dfs(u + 1, 0, 0)) % MOD;
			} else {
				res = (res + dfs(u + 1, 0, 1)) % MOD;
			}
			if (prevType == 1) {
				res = (res + dfs(u + 1, 0, 1)) % MOD;
			}
			if (type == 2) {
				res = (res + dfs(u + 1, 1, 2)) % MOD;
			}
		}
	} else {
		if (str[u] == '*') {
			if (type == 0) {
				res = 0; 
			} else {
				res = (res + dfs(u + 1, 1, 2)) % MOD;
			}
		} else {
			if (type == 1) {
				res = 0; 
			} else {
				if (str[u] == '0') {
					if (prevType == 1) {
						res = 0;
					} else {
						res = (res + dfs(u + 1, 0, 0)) % MOD;
					}
				} else if (str[u] == '1') {
					if (prevType == 1) {
						res = (res + dfs(u + 1, 0, 0)) % MOD;
					} else {
						res = (res + dfs(u + 1, 0, 1)) % MOD;
					}
				} else {
					if (prevType == 1) {
						res = (res + dfs(u + 1, 0, 1)) % MOD; 
					} else {
						res = 0;
					}
				}
			}
		}
	}
	return memo[u][prevType][type] = res % MOD;
}

void solve() {
	cin >> str; n = strlen(str);
	memset(memo, -1, sizeof memo);
	cout << dfs(0, 0, 2) << endl;
}

signed main() {
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int t = 1;
	// cin >> t;
	while (t--) solve();
	return 0;
}
