#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

LL n, x, y;

LL gcd(LL a, LL b) {
    return b ? gcd(b, a % b) : a;
}
void solve() {
    cin >> n >> x >> y;
    LL res = 0;
    LL maxv = n, minv = 1;
    LL z = x * y / gcd(x, y);
    LL c = n / z, a = n / x - c, b = n / y - c;
    res += a * n + a * (a - 1);
    res -= b * 1 + b * (b - 1) * (-1);
    cout << res << endl;
}
int main() {

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}