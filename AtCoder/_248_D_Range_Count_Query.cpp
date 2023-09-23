#include <bits/stdc++.h>
using namespace std;


unordered_map<int, vector<int>> mp;

int solve(int l, int r, int x) {
	int left = lower_bound(mp[x].begin(), map[x].end(), l) - mp[x].begin();
	int right = upper_bound(mp[x].begin(), mp[x].end(), r) - mp[x].begin() - 1;
	return right - left + 1;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		mp[x].push_back(i);
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x);
		printf("%d\n", solve(l, r, x));
	}
	return 0;
}

