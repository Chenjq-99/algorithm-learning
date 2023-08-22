 #include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 1 << 24;

int n, m, k;
int w[N], g[50];
int cnt;
int ans;

void dfs1(int u, int s) {
    if (u == k) {
        w[cnt++] = s;
        return;
    }
    dfs1(u + 1, s);
    if ((LL)s + g[u] <= m) dfs1(u + 1, s + g[u]);
}

void dfs2(int u, int s) {
    if (u == n) {
        int l = 0, r = cnt - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (w[mid] + (LL)s <= m) l = mid;
            else r = mid - 1;
        }
        if ((LL)s + w[r] <= m)
            ans = max(ans, s + w[r]);
        return;
    }
    dfs2(u + 1, s);
    if ((LL)s + g[u] <= m) dfs2(u + 1, s + g[u]);
}


int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++)
        cin >> g[i];
    
    sort(g, g + n, greater<int>());
    
    k = n / 2;
    dfs1(0, 0);
    sort(w, w + cnt);
    cnt = unique(w, w + cnt) - w;
    dfs2(k, 0);
    cout << ans << endl;
    return 0;
}
