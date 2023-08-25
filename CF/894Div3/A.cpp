#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

const int N = 25;
int n, m;
int g[N][N];
string s = "vika";

bool solve() {
    cin >> n, m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];
    int cnt = 0;
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++) {
            if (g[i][j] = s[cnt]) {
                cnt++;
                break;
                if (cnt == 4) return true;
            }
        }
    return false;
}
int main() {

    int t;
    cin >> t;

    while (t--) {
        cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}