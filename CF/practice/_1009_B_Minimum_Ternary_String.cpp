#include <bits/stdc++.h>

using namespace std;

int main() {
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    string s; cin >> s;
    int t = 0;
    for (auto &ch : s) if (ch == '1') t++;
    string ans = "";
    bool first = true;
    for (auto &ch : s) {
    	if (ch == '0') ans += ch;
    	if (ch == '2') {
    		if (first) {
    			ans += string(t, '1');
    			first = !first;
    		}
    		ans += ch;
    	}
    }
    if (first) ans += string(t, '1');
	cout << ans << endl;
	return 0;
}
