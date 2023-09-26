#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

const int N = 110;
int n, x;
int a[N];

int main() {
	
	cin >> n >> x;
	int sum, ans;
	int minv = 1e9, maxv = 0;
	for (int i = 0; i < n - 1; i++) {
		cin >> a[i];
		sum  += a[i];
		maxv = max(maxv, a[i]);
		minv = min(minv, a[i]);
	}

	if (sum - minv < x) {
		ans = -1;
	} else {
		if (sum - maxv >= x) {
			ans = 0;
		} 
		else if (x - sum + maxv + minv >= minv && x - sum + maxv + minv <= maxv) {
			ans = x - sum + maxv + minv;
		}
		else if (sum - minv >= x) {
			ans = maxv;
		}
	}
	cout << ans << endl;
	return 0;
}