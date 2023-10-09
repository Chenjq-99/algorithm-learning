// https://codeforces.com/problemset/problem/1368/D
#include<bits/stdc++.h>
using namespace std;

int main () {

    int n; cin >> n;
    vector<int> bits(63, 0);
    for (int i = 0; i < n; i++) {
        long long x; cin >> x;
        for (int j = 0; j < 63; j++) {
            bits[j]++;
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long x = 0;
        for (int j = 0; j < 63; j++) {
            if (bits[j] >= 1) {
                x |= (1 << j);
                bits[j]--;
            }
        }
        ans += x * x;
    }
    cout << ans << endl;
    return 0;
}