#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

const int N = 200010;
int n;
int a[N];
int b[N];

void solve() {
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    int cnt = mp.size();
    sort(a, a + n, greater<int>());
    for (int i = 1; i < n; i++) {
        mp[i] -= a[i] - a[i - 1];
        if (mp[i] == 0) {
            cnt--;
        } else if (mp[i] < 0) {
            cout << "NO" << endl;
            return;
        }
    }
    if (cnt == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
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