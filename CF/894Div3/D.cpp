#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

LL n;

void solve() {
    cin >> n;
    // maxmize (m) s.t. m * (m - 1) / 2  <= n 
    LL l = 2, r = n;
    while (l < r) {
        LL mid = l + r + 1 >> 1;
        if (mid * (mid - 1) / 2 <= n) l = mid;
        else r = mid - 1;
    }
    LL t = l * (l - 1) / 2;
    cout << l + (n - t) << endl;
    return;
}
int main() {

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}