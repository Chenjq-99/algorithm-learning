#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second

typedef pair<int, int> PII;

signed main() {
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int q; cin >> q;
	set<PII> st;
	while (q--) {
		char op; int l, r;
		cin >> op >> l >> r;
// 		cout << op << l << r << endl;
		if (op == '+') {
			st.emplace(l, r);
		} else {
			st.erase({l, r});
		}
	}
	if (st.size() == 0) {
	    puts("YES");
	} else {
    	int l = (*st.begin()).x, r = (*st.begin()).y;
    	auto it = st.begin(); it++;
    	bool ok = true;
    	while (it != st.end()) {
    		if (r < (*it).x) {
    			l = (*it).x, r = (*it).y;
    		} else {
    			ok = false;
    			break;
    		}
    		it++;
    	}
    	if (ok) {
    		puts("YES");
    	} else {
    		puts("NO");
    	}
	}
	return 0;
}
