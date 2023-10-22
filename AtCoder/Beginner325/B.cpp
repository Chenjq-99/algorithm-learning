#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second

typedef pair<int, int> PII;


signed main() {
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; cin >> n;
    vector<int> w(n);
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
    	cin >> w[i] >> x[i];
    }
    int ans = 0;
    for (int i = 0; i < 24; i++) {
    	int cnt = 0;
    	for (int j = 0; j < n; j++) {
    		int t = (i + x[j]) % 24;
    		if (t >= 9 && t + 1 <= 18) {
    			cnt += w[j];
    		}
    	}
    	ans = max(ans, cnt);
    }
    cout << ans << endl;
	return 0;
}