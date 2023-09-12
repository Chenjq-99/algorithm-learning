#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

const int N = 100010;

int n;
int a[N], s[N];
string str;

void solve() {
    cin >> n;
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = a[i] ^ s[i - 1];
    }
    cin >> str;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') x ^= a[i + 1];
        else y ^= a[i + 1];
    }
    cout << "-------" << x << " " << y << endl;
    int q;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            int z = s[r] ^ s[l - 1];
            x ^= z;
            y ^= z;
        } else {
            int g;
            cin >> g;
            if (g == 0) cout << x << " ";
            else cout << y << " ";
        }
    }
    cout << endl;
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