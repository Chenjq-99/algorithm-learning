#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second

typedef pair<int, int> PII;


signed main() {
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m; vector<int> days(m);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
    	cin >> days[i];
    }
    for (int i = 1; i <= n; i++) {
    	int t = *lower_bound(days.begin(), days.end(), i);
    	cout << t - i << endl;
    }
	return 0;
}