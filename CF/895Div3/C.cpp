#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int l, r;

int check(int x) {
    if (x < 2) return -1;
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) return i;
    }
    return -1;
}
void solve() {
    cin >> l >> r;
    int k = r, v = -1;
    while (k >= l) {
        v = check(k);
        if (v == -1) k--;
        else break;
    }
    if (k < l) cout << -1 << endl;
    else {
        cout << v << " " << k - v << endl;
    }
}
int main() {

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}