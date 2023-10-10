// https://codeforces.com/problemset/problem/1690/E
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, a[N], k;

int main() {
    int T; cin >> T;
    while (T--) {
        cin >> n >> k;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            ans += a[i] / k;
            a[i] %= k;
        }
        sort(a, a + n);
        int l = 0, r = n - 1;
        while (l < r) {
            if (a[l] + a[r] < k) l++;
            else {
                ans += 1;
                l++, r--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}