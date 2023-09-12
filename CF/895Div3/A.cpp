#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int a, b, c;

void solve() {
    cin >> a >> b >> c;
    double dif = abs(a - b) / 2.0, x = dif / c;
    if (x > (int)x) cout << (int)x + 1 << endl;
    else cout << (int)x << endl;
}
int main() {

    int t;
    cin >> t;

    while (t--) solve();
    return 0;
}