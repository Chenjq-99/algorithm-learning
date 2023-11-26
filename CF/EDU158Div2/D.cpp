#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n, a[N];

bool check(long long x) {
	int l = 0, r = n - 1;
	for (int i = 0; i < n; i++) {
		if (x - a[i] < 0) return false;
		if (a[i] > x - (n - i - 1)) {
			r = min(r, i);
		} 
		if (a[i] > x - i) {
			l = max(l, i);
		}
	}
	return l <= r;
}

int main() {
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    long long l = 0, r = (long long)1e9 * N;
	while (l < r) {
		long long mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << r << endl;
	return 0;
}
