#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    string x, s;
    cin >> n >> m >> x >> s;
    int res = 0;
    while (x.length() < s.length()) x += x, res++;
    if (x.find(s) != string::npos) {
        cout << res << endl;
    } else if (string(x + x).find(s) != string::npos) {
        cout << res + 1 << endl;
    } else {
        cout << -1 << endl;
    }
    return;
}
int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}