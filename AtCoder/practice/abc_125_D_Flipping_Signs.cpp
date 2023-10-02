#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int n;

int main() {
	cin >> n;
	long long sum = 0;
	int minv = INT32_MAX, cnt = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x < 0) {
			cnt++;
			x = -x;
		}
		sum += x;
		minv = min(minv, x);
	}
	if (cnt & 1) cout << sum - 2 * minv << endl;
	else cout << sum << endl;
	return 0;
}