#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n;
char s[N];

void solve() {
	scanf("%s", s);
	n = strlen(s);
	vector<int> Bid = {-1};
	for (int i = 0; i < n; i++)
		if (s[i] == 'B')
			Bid.push_back(i);
	Bid.push_back(n);
	int m = Bid.size() - 2;
	if (m == 0) printf("%d\n", 0);
	else {
		vector<int> left, right;
		for (int i = 1; i <= m; i++) {
			left.push_back(Bid[i] - Bid[i - 1] - 1);
			right.push_back(Bid[i + 1] - Bid[i] - 1);
			// cout << i << " " << left[i - 1] << " " << right[i - 1] << endl;
		}

		int f[m][2];
		memset(f, 0, sizeof(f));
		f[0][0] = left[0], f[0][1] = right[0]; 
		for (int i = 1; i < m; i++) {
			f[i][0] = f[i - 1][0] + left[i];
			f[i][1] = max(f[i - 1][0] + right[i], f[i - 1][1] + right[i]);
		}
		printf("%d\n", max(f[m - 1][0], f[m - 1][1]));
	}
}

int main() {
	int t; scanf("%d", &t);
	while (t--) solve();
	return 0;
}
