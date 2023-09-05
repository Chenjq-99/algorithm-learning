// https://leetcode.cn/problems/minimum-edge-weight-equilibrium-queries-in-a-tree/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

class Solution {
    typedef pair<int, int> pii;
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int depth[n], cnt[n][15][27], f[n][15];
        memset(depth, 0, sizeof depth);
        memset(cnt, 0, sizeof cnt);
        memset(f, -1, sizeof f);
        vector<vector<pii>> g(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1], w = e[2];
            g[a].emplace_back(b, w);
            g[b].emplace_back(a, w);
        }
        function<void(int, int, int)> dfs = [&](int u, int fa, int w) {
            if (fa != -1) depth[u] = depth[fa] + 1;
            f[u][0] = fa;
            cnt[u][0][w] = 1;
            for (auto& p : g[u])
            {
                if (p.first == fa) continue;
                dfs(p.first, u, p.second);
            }
        };
        dfs(0, -1, 0);
        for (int i = 1; i < 15; i++) {
            for (int p = 0; p < n; p++) {
                if (f[p][i - 1] != -1) {
                    f[p][i] = f[f[p][i - 1]][i - 1];
                    for (int k = 1; k <= 26; k++) {
                        cnt[p][i][k] = cnt[p][i - 1][k] + cnt[f[p][i - 1]][i - 1][k];
                    }
                }
            }
        }

        function<int(int, int)> get_lca = [&](int a, int b) -> int {
            int cnt1[27] = {0};
            if(depth[a] < depth[b]) swap(a, b);
            int len = depth[a] + depth[b];
            for(int i = 14; i >= 0; i--)
                if(f[a][i] != -1 && depth[f[a][i]] >= depth[b]) {
                    for (int j = 1; j <= 26; j++) {
                        cnt1[j] += cnt[a][i][j];
                    }
                    a = f[a][i];
                }
            int lca = 0;
            if(a == b) lca = b;
            else {
                for(int i = 14; i >= 0 ; i--)
                if(f[a][i]!= f[b][i])
                {
                    for (int j = 1; j <= 26; j++) {
                        cnt1[j] += cnt[a][i][j] + cnt[b][i][j];
                    }
                    a = f[a][i];
                    b = f[b][i];
                }
                lca = f[a][0];
                for (int j = 1; j <= 26; j++) {
                    cnt1[j] += cnt[a][0][j] + cnt[b][0][j];
                }
            }
            
            return len - 2 * depth[lca] - *max_element(cnt1 + 1, cnt1 + 27);
        };
        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            int a = queries[i][0], b = queries[i][1];
            ans[i] = get_lca(a, b);
        }
        return ans;
    }
};