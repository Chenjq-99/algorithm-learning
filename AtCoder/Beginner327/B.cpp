#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second

typedef pair<int, int> PII;


signed main() {
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int b;
    cin >> b;
    int ans = -1;
    for (int i = 1; i <= 15; i++) {
    	int res = 1;
    	for (int j = 0; j < i; j++) {
    		res = res * i;
    	}
    	if (res == b) {
    		ans = i;
    		break;
    	}
    }
    cout << ans << endl;
	return 0;
}