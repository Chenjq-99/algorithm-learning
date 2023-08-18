// minimize [sum(2 * ri * hi) + r0 * r0] s.t. sum(ri * ri * hi) = N 

#include<bits/stdc++.h>
using namespace std;

int n, m;
int ans = 0x3f3f3f3f;

void dfs(int u, int s, int v, int last_r, int last_h) {
    // 预测总表面积最小值
    int t = s + 2 * (n - v) / last_r; 
    if (t >= ans || v > n) return;
    if (u == 0) {
        if(v == n) ans = min(ans, s);
        return;
    }
    for (int r = last_r - 1; r >= u; r--) {
        for (int h = last_h - 1; h >= u; h--) {
            if (v + r * r * h > n) continue;
            dfs(u - 1, s + 2 * r * h, v + r * r * h, r, h);
        }
    }
}
int main() {
    cin >> n >> m;
    for (int r0 = (int)sqrt(n); r0 >= 1; r0--) {
        for (int h0 = n / (r0 * r0); h0 >= 1; h0--) {
            int s0 = r0 * r0 + 2 * r0 * h0, v0 = r0 * r0 * h0;
            dfs(m - 1, s0, v0, r0, h0);
        }
    }
    if (ans >= 0x3f3f3f3f / 2) ans = 0;
    cout << ans << endl;
    return 0;    
}