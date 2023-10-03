#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3010, MOD = 998244353;

int n, a[N], b[N], f[N], s[N];

signed main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >>n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    // for (int i = a[0]; i <= b[0]; i++) f[0][i] = i - a[0] + 1;
    // for (int i = 1; i < n; i++) {
    // 	for (int j = a[i]; j <= b[i]; j++) {
    // 		f[i][j] = ((long long)f[i][j - 1] + f[i - 1][min(j, b[i - 1])]) % MOD;
    // 	}
    // }
    // cout << f[n - 1][b[n - 1]] << endl;

    for (int i = a[0]; i <= b[0]; i++) f[i] = 1;
   	s[0] = f[0];
    for (int i = 1; i < N; i++) s[i] = (f[i] + s[i - 1]) % MOD;
    for (int i = 1; i < n; i++) {
    	memset(f, 0, sizeof f);
    	for (int j = a[i]; j <= b[i]; j++) f[j] = s[j];
    	memset(s, 0, sizeof s);
    	s[0] = f[0];
    	for (int j = 1; j < N; j++) s[j] = (f[j] + s[j - 1]) % MOD;
    }
	cout << s[b[n - 1]] << endl;	
    return 0;
}