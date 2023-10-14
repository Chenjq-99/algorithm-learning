#include <bits/stdc++.h>
using namespace std;

const int N = 1010, M = N * N;

int n;
char g[N][N];
int p[M];

int find(int x) {
    return p[x] == x ? p[x] : p[x] = find(p[x]);
}


int solve() {
    cin >> n;
    for (int i = 0; i < n * n; i++) p[i] = i;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
            if (n - j >= 0) {
                int px = find(i * n + j);
                int py = find((n - j - 1) * n + i);
                if (px != py) p[px] = py;
            }
        }
    }
    map<int, vector<int>> hash;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            hash[find(i * n + j)].push_back(g[i][j] - '0');
        }
    }
    int res = 0;
    for (auto& [k, v] : hash) {
       int max_v = *max_element(v.begin(), v.end());
       for (int x : v) res += max_v - x;
    }
    cout << res << endl;
}
int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}