#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int q; std::cin >> q;
	std::multiset<int> stl, str;
	char op;
	int l, r;
	while (q--) {
		std::cin >> op >> l >> r;
		if (op == '+') {
			stl.insert(l);
			str.insert(r);
		} else {
			stl.erase(stl.find(l));
			str.erase(str.find(r));
		}
		if (str.size() && *(str.begin()) < *(stl.rbegin())) {
			std::cout << "YES" << std::endl;
		} else {
			std::cout << "NO" << std::endl;
		}
	}
	return 0;
}