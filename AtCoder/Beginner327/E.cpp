#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second

typedef pair<int, int> PII;

const int N = 5010;

int n, p[N];
double f[N];

signed main() {
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
    	for (int j = i; j >= 0; j--) {
    		f[j + 1] = max(f[j + 1], f[j] * 0.9 + p[i]);
    	}
    }
    double den = 0;
    double ans = -1200;
    for (int k = 1; k <= n; k++) {
    	den = den * 0.9 + 1;
    	ans = max(ans, f[k] / den - 1200 / sqrt(k));
    }
    cout << std::fixed << std::setprecision(10) << ans << endl;
	return 0;
}