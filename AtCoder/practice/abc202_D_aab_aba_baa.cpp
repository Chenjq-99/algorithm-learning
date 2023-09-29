// https://atcoder.jp/contests/abc202/tasks/abc202_d
#include <bits/stdc++.h>
using namespace std;

const int N = 65;

long long a, b, k, f[N][N];
char str[N];

void init() {
	for (int i = 0; i < N; i++) f[i][0] = 1;
	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= i; j++) {
			f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
		}
	}
}
int main() {
	init();
	cin >> a >> b >> k;
	int n = a + b;
	for (int i = 0; i < n; i++) {
		if (f[a + b - 1][b] < k) {
			k -= f[a + b - 1][b];
			b--;
			str[i] = 'b';
		} else {
			a--;
			str[i] = 'a';
		}
	}
	for (int i = 0; i < n; i++) {
		cout << str[i];
	}
	return 0;
}