#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second

typedef pair<int, int> PII;


signed main() {
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; string str;
    cin >> n >> str;
    int ans = -1;
    for (int i = 0; i < n - 2; i++) {
        if (str.substr(i, 3) == "ABC") {
            ans = i + 1;
            break;
        }
    }
    cout << ans << endl;
	return 0;
}