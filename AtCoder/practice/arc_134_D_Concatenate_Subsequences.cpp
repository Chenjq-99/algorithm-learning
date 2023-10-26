#include <bits/stdc++.h>

int main() {
	int n; std:: cin >> n;
	std::vector<int> A(2 * n + 1);
	for (int i = 1; i <= 2 * n; i++) {
		std::cin >> A[i];
	} 
	std::vector<int> a, b;
	for (int i = 1; i <= n; i++) {
		while (a.size() && A[i] < a.back()) {
			a.pop_back();
			b.pop_back();
		}
		a.push_back(A[i]);
		b.push_back(A[i + n]);
	}
	int i = upper_bound(a.begin(), a.end(), a[0]) - a.begin();
	int minv = *(std::min_element(b.begin(), b.begin() + i));
	if (minv <= a[0]) {
		std::cout << a[0] << " " << minv << std::endl;
	} else {
		std::vector<int> x, y;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] < b[0]) {
				x.push_back(a[i]);
				y.push_back(b[i]);
			}
		}
		int pos = -1;
		for (int i = 0; i < y.size(); i++) {
			if (y[i] != y[0]) {
				pos = i;
				break;
			}
		}		
		if (pos != -1 && y[pos] > y[0]) {
			for (int i = 0; i < a.size(); i++) {
				if (a[i] == y[0]) {
					x.push_back(a[i]);
					y.push_back(b[i]);
				}
			}
		}
		for (int i = 0; i < x.size(); i++) {
			std::cout << x[i] << " ";
		}
		for (int i = 0; i < y.size(); i++) {
			std::cout << y[i];
			if (i < y.size() - 1) {
				std::cout << " ";
			}
		}
	}
	return 0;
}