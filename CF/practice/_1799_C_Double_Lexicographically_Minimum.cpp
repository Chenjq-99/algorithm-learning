// https://codeforces.com/contest/1799/problem/C
#include <bits/stdc++.h>
using namespace std;

string work(int cnt[], int last) {
    int _1st = -1, _2nd = -1;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > 0) {
            if (_1st == -1) {
                _1st = i;
            }
            else if (_2nd == -1) {
                _2nd = i;
            }
            else {
                break;
            }
        }
    }
    string res = "";
    if (_1st == -1) {
        return res;
    } else if (_2nd == -1) {
        char ch1 = char('a' + _1st);
        for (int i = 0; i < cnt[_1st]; i++) {
            res += ch1;
        }
        return res;
    }
    char ch1 = char('a' + _1st), ch2 = char('a' + _2nd);
    if (cnt[_1st] >= 2) {
        cnt[_1st] -= 2;
        res = ch1 + work(cnt, last - 2) + ch1;
    } else if (cnt[_2nd] >= 2 && last - cnt[_2nd] == cnt[_1st]) {
        cnt[_2nd] -= 2;
        res = ch2 + work(cnt, last - 2) + ch2;
    } else {
        cnt[_1st] -= 1, cnt[_2nd] -= 1;
        res += ch2;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < cnt[i]; j++) {
                res += char('a' + i);
            }
        }
        res += ch1;
    }
    return res;
}

void solve() {
    string s; cin >> s;
    int cnt[26] = {0};
    for (auto& ch : s) cnt[ch - 'a']++;
    cout << work(cnt, s.size()) << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}