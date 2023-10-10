#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second

typedef pair<int, int> PII;

const int N = 5010, MOD = 998244353;

int q, k, f[N];

char op[2]; int x;

signed main() {
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> q >> k;

    f[0] = 1;

    while (q--) {
    	cin >> op >> x;
    	if (*op == '+') 
    		for (int i = k; i >= x; i--)
    			f[i] = (f[i] + f[i - x]) % MOD;
    	else
    		for (int i = x; i <= k; i++) 
    			f[i] = (f[i] - f[i - x] + MOD) % MOD;
    	cout << f[k] << endl;
    }

	return 0;
}