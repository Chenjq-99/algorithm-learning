#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second

typedef pair<int, int> PII;


signed main() {
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    string str;
    cin >> n >> str;
    bool ok = false;
    for (int i = 0; i < n - 1; i++) {
    	string tmp = str.substr(i, 2);
    	if (tmp == "ab" || tmp == "ba") {
    		ok = true;
    		break;
    	}
    }
    if (ok) {
    	puts("Yes");
    } else {
    	puts("No");
    }
	return 0;
}