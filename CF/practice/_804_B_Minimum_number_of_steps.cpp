#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
	string str;	cin >> str;
	int res = 0, cnt = 0;
	for (int i = str.length() - 1; i >= 0; i--) {
		if (str[i] == 'a') {
			res = (res + cnt) % MOD;
			cnt = 2LL * cnt % MOD;
		} else {
			cnt += 1;
		}
	}
	cout << res << endl;
	return 0;
}