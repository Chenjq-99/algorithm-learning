#include <bits/stdc++.h>
using namespace std;

string str;
long long n;
long long x;
vector<long long> v;

int mian() {
	cin >> str >> n;
	int m = str.size();
	for (int i = 0; i < m; i++) {
		if (str[i] == '1') x ^= 1LL << (m - 1 - i);
		else if (str[i] == '?') v.push_back(1LL << (m - 1 - i));
	}
	for (int i = 0; i < v.size(); i++) {
		if (x ^ v[i] <= n) {
			x ^= v[i];
		}
	}
	cout << x << endl;
	return 0;
}