#include<bits/stdc++.h>

using namespace std;

const int N = 20;

int n, W;
int w[N];
int group[N];
int ans = N;

void dfs(int u, int gc) {
    if (gc >= ans) return;
    if (u == n) { 
        ans = min(ans, gc);
        return; 
    }
    for (int i = 1; i <= gc; i++) {
        if (group[i] + w[u] > W) continue;
        group[i] += w[u];
        dfs(u + 1, gc);
        group[i] -= w[u];
    }
    group[gc + 1] = w[u];
    dfs(u + 1, gc + 1);
    group[gc + 1] = 0;

}

int main() {
    cin >> n >> W;
    for (int i = 0; i < n; i++)
        cin >> w[i];
    // ÓÅ»¯ËÑË÷Ë³Ðò
    sort(w, w + n, greater<int>());
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}