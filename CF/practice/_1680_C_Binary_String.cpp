// https://codeforces.com/contest/1680/problem/C
#include<bits/stdc++.h>
using namespace std;

string s;

bool check(int limit, int n, int m) {
    int cnt0 = 0, cnt1 = 0;
    for (int r = 0, l = 0; r < n; r++) {
        if (s[r] == '0') {
            cnt0++;
        } else {
            cnt1++;
        }
        while (l < r && cnt0 > limit) {
            if (s[l] == '0') {
                cnt0--;
            } else {
                cnt1--;
            }
            l++;
        }
        if (m - cnt1 <= limit) {
            return true;
        }
    }
    return false;
}
int main() {
    int T; cin >> T;
    while (T--) {
        cin >> s;
        int n = s.size(), m = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                m++;
            }
        }
        int l = 0, r = n;
        while (l < r) {
            int mid  = (l + r) >> 1;
            if (check(mid, n, m)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << r << endl;
    }
    return 0;
}