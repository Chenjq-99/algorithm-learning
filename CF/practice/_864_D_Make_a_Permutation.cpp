#include <bits/stdc++.h>

const int N = 200010;
int n, a[N];
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> n;
	std::vector<int> cnt(n + 1,0);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		cnt[a[i]]++;
	}
	std::vector<int> lack;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0) {
			lack.push_back(i);
		}
	}
	std::cout << lack.size() << std::endl;
	int j = 0;
	std::vector<bool> st(n + 1);
	for (int i = 0; i < n; i++) {
		if (cnt[a[i]] > 1) {
			if (a[i] > lack[j] || st[a[i]]) {
				cnt[a[i]]--;
				a[i] = lack[j++];
			} else {
				st[a[i]] = true;
			}
		}
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}