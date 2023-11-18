#include <iostream>
#include <vector>

const int N = 40000, MOD = 1e9 + 7;
std::vector<int> p;
std::vector<long long> f(N + 1,0);

void init() {
	for (int i = 1; i <= 9; i++) {
		p.push_back(i);
	}
	for (int i = 1; i <= 9; i++) {
		p.push_back(i * 10 + i);
	}
	for (int i = 1; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			p.push_back(i * 100 + j * 10 + i);
		}
	}
	for (int i = 1; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			p.push_back(i * 1000 + j * 100 + j * 10 + j);
		}
	}
	for (int i = 1; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k<= 9; k++) {
				p.push_back(i * 10000 + j * 1000 + k * 100 + j * 10 + i);
			}
		}
	}
	f[0] = 1;
	for (int i = 0; i < p.size(); i++) {
		for (int j = 0; j <= N - p[i]; j++) {
			f[j + p[i]] += f[j];
			f[j + p[i]] %= MOD;
		}
	}
}

void solve() {
	int n; std::cin >> n;
	std::cout << f[n] << std::endl;
	return;
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	init();

	int t; std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}