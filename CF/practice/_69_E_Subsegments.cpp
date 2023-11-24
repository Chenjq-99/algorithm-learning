#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int n, k, a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	map<int, int> cnt;
	set<int> once; 
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int r = 1, l = 1; r <= n; r++) {
		if (r <= k) {
			cnt[a[r]]++;
		} else {
			cnt[a[r]]++;
			cnt[a[l]]--;
		}
		if (cnt[a[r]] == 1 && !once.count(a[r])) {
			once.insert(a[r]);
		}
		if (cnt[a[r]] != 1 && once.count(a[r])) {
			once.erase(a[r]);
		}
		if (cnt[a[l]] == 1 && !once.count(a[l])) {
			once.insert(a[l]);
		}
		if (cnt[a[l]] != 1 && once.count(a[l])) {
			once.erase(a[l]);
		}
		if (r >= k) {
			if (once.empty()) {
				cout << "Nothing" << endl;
			} else {
				cout << *once.rbegin() << endl;
			}
			if (r > k) l++;
		}
	}
	return 0;
}
