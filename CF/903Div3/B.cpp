#include <bits/stdc++.h>   
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int x = gcd(gcd(a, b), c);
    if ((a + b + c) / x - 3 > 3) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}