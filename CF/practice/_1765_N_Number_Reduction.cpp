// https://codeforces.com/problemset/problem/1765/N
#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s; int k;
    cin >> s >> k;
    int j = 0;
    for (int i = 0; i <= k; i++) {
        if (s[i] > '0' && s[j] > s[i]) {
            j = i;
        }
    }
    k -= j;
    string stk(1, s[j]);
    for (int i = j + 1; i < s.size(); i++) {
        while (stk.size() > 1 && stk[stk.size() - 1] > s[i] && k > 0) {
            stk.pop_back();
            k--;
        }
        stk.push_back(s[i]);
    }
    ;
    while (k--) {
        stk.pop_back();
    }
    cout << stk << endl;
    return;
}

int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}