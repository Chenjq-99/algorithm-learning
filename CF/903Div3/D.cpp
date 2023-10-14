#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n; cin >> n;
    map<int, int> hash;  
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        for (int p = 2; p <= x / p; p++) {
            while (x % p == 0) {
                x /= p;
                hash[p]++;
            }
        }
        if (x != 1) hash[x]++;
    }
    bool success = true;
    for (auto& [k, v] : hash) {
        if (v % n != 0) {
            success = false;
            break;
        }
    }
    if (success) puts("YES");
    else puts("NO");
}
int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}