#include <bits/stdc++.h>
using namespace std;

vector<long long> nums;

void dfs(long long x) {
	for (int i = 0; i < x % 10; i++) {
		nums.push_back(x * 10 + i);
		dfs(x * 10 + i);
	}
}
int main() {
	long long k;
	cin >> k;
	for (int i = 1; i <= 9; i++) {
		nums.push_back(i);
		dfs(i);
	}
	sort(nums.begin(), nums.end());
	cout << nums[k - 1] << endl;
	return 0;
}