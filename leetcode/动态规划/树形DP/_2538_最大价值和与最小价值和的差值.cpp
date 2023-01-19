#include<vector>
#include<cstring>
using namespace std;
// https://leetcode.cn/problems/difference-between-maximum-and-minimum-price-sum/
// 换根dp
class Solution {
public:
    typedef long long LL;
    static const int N = 100010, M = 2 * N;
    int h[N], e[M], ne[M], idx = 0;
    void add(int a, int b) {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }
    LL f1[N],f2[N], up[N]; // 往下走的最大值，次大值，往上走的最大值
    vector<int> w;
    int n;
    // 求u向下走最大值
    LL dfs_d(int u, int fa) {
        f1[u] = w[u];
        for (int i = h[u]; i != -1; i = ne[i]) {
            int j = e[i];
            if (j == fa) continue;
            LL d = dfs_d(j, u) + w[u];
            if (d > f1[u]) f2[u] = f1[u], f1[u] = d;
            else if (d > f2[u]) f2[u] = d;
        }
        return f1[u];
    }
    // 求j向上走最大值
    void dfs_u(int u, int fa) {
        for (int i = h[u]; i != -1; i = ne[i]) {
            int j = e[i];
            if (j == fa) continue;
            if(f1[u] == f1[j]+w[u]) up[j] = max(up[u], f2[u]) + w[j];//最大值被j占用
            else up[j] = max(up[u], f1[u]) + w[j];
            dfs_u(j, u);
        }
    }
    LL maxOutput(int _n, vector<vector<int>>& edges, vector<int>& _w) {
        memset(h, -1, sizeof h);
        n = _n, w = _w;
        for(auto &e : edges) add(e[0],e[1]), add(e[1],e[0]);
        dfs_d(0,-1);
        dfs_u(0,-1);
        LL res = 0;
        for(int i = 0; i < n; i++) res = max(res, max(f1[i], up[i]) - w[i]);
        return res;
    }
};