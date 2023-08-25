#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

const int N = 200010;

int n, m, d;
int a[N];
LL s[N];

void solve() {
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    priority_queue<LL, vector<LL>, greater<LL>> pq;
    LL sum = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        s[i] = sum + a[i];
        if (a[i] > 0) 
        {
            pq.push(a[i]);
            sum += a[i];
        }
        if (pq.size() > m - 1) {
            sum -= pq.top();
            pq.pop();
        }
        ans = max(ans, s[i] - (LL) d * i);
    }
    printf("%lld\n", ans);
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