#include <bits/stdc++.h>

int main() {
	int n; std::cin >> n;
	std::vector<int> c(n + 1), d(n + 1);
	int INF = 0x3f3f3f3f, l = -INF, r = INF;
	for (int i = 1; i <= n; i++) {
		std::cin >> c[i] >> d[i];
		c[i] += c[i - 1];
	} 
	for (int i = 0; i < n; i++) {
		if (d[i + 1] == 1) {
			l = std::max(l, 1900 - c[i]);
		} else {
			r = std::min(r, 1899 - c[i]);
		}
	}
	if (l > r) {
		puts("Impossible");
	} else if (r == INF) {
		puts("Infinity");
	} else {
		std::cout << r + c[n] << std::endl;
	}
	return 0;
}