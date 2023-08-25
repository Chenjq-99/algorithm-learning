#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

const int N = 200010, M = 2 * N;
int n, m;
int b[N];
int a[N];

void solve() {
    cin >> n;
    m = 0;
    for (int i = 0; i < n; i++) cin >> b[i];
    a[m++] = b[0];
    for (int i = 1; i < n; i++) {
        if (b[i - 1] > 1) 
            a[m++] = min(b[i - 1] - 1, b[i]);
        a[m++] = b[i];
    }
    cout << m << endl;
    for (int i = 0; i < m; i++)
        cout << a[i] << ' ';
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