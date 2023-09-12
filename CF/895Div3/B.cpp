#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

const int N = 110;
int n;
int d[N];
int s[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> d[i] >> s[i];
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        int x = d[i] - 1 + s[i];
        int k = d[i];
        while ((k - d[i]) * 2 + (d[i] - 1) < x) k++;
        ans = min(ans, max(k - 1, d[i]));
    }
    cout << ans << endl;
}

int main() {

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}