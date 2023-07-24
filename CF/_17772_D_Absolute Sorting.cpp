#include<bits/stdc++.h>

using namespace std;

const int N = 200010;

int T, n, l, r;

int a[N];

int main () {
    cin >> T;
    while (T--) {
        cin >> n;
        l = -1e9, r = 1e9;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n - 1; i++) {
            if (a[i] < a[i + 1]) {
                // x - a[i] <= a[i + 1] - x
                r = min(r, (a[i] + a[i + 1]) / 2);
            } else if (a[i] > a[i + 1]) {
                // a[i] - x <= x - a[i + 1]
                l = max(l, (a[i] + a[i + 1] + 1) / 2);
            }
        }
        cout << ((l <= r) ? max(0, l) : -1) << endl;
    }
    return 0;
}