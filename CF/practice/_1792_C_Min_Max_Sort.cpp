// https://codeforces.com/problemset/problem/1792/C
#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, a[N];

void solve() {
    cin >> n; 
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        a[x] = i;
    }
    int k = (n >> 1);
    while (k && a[k] < a[k + 1] && a[n - k + 1] > a[n - k]) k--;
    cout << k << endl;
}

int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}