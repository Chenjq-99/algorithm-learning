#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second

typedef pair<int, int> PII;

const int N = 300010;

int n, k;
PII bt[N];

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> bt[i].y >> bt[i].x;
	}	
	sort(bt, bt + n);
	priority_queue<int, vector<int>, greater<int>> pq;
	int sum = 0, ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		ans = max(ans, bt[i].x * (bt[i].y + sum));
		if (k > 1) {
			if (pq.size() < k - 1) {
				pq.push(bt[i].y);
				sum += bt[i].y;
			} else {
				if (bt[i].y > pq.top()) {
					sum += bt[i].y - pq.top();
					pq.pop();
					pq.push(bt[i].y);
				}
			}
		}
	}
	cout << ans << endl;
	return;
}

signed main() {
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int t = 1;
	// cin >> t;
	while (t--) solve();
	return 0;
}
