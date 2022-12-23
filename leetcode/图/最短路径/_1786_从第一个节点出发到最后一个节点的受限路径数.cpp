#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

class Solution {
private:
    typedef long long LL;
    typedef pair<int, LL> pILL;
    static const int N = 2e4 + 10, M = 8e4 + 10, MOD = 1e9 + 7;
    int h[N], e[M], w[M], ne[M], idx = 0;
    LL dist[N];
    bool st[N];
    int n;
    void add(int a, int b, int wt) {
        e[idx] = b, w[idx] = wt, ne[idx] = h[a], h[a] = idx++;
    }
    void dijkstra() {
        memset(dist, 0x3f, sizeof dist);
        memset(st, false, sizeof st);
        dist[n] = 0;
        priority_queue<pILL, vector<pILL>, greater<>> heap;
        heap.emplace(0, n);
        while (heap.size()) {
            auto t = heap.top();
            heap.pop();
            int ver = t.second, wt = t.first;
            if (st[ver]) continue;
            st[ver] = true;
            for (int i = h[ver]; i != -1; i = ne[i]) {
                int j = e[i];
                if (dist[j] > wt + w[i]) {
                    dist[j] = wt + w[i];
                    heap.emplace(dist[j], j);
                }
            }
        }
    } 
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        this->n = n;
        memset(h, -1, sizeof h);
        for (auto& e : edges) {
            int a = e[0], b = e[1], wt = e[2];
            add(a, b, wt), add(b, a, wt);
        } 
        dijkstra();
        LL dp[n + 1]; // dp[i] 表示从1->i受限制的路径数
        memset(dp, 0, sizeof dp);
        dp[1] = 1;
        int id[n + 1];
        for (int i = 1; i <= n; i++) id[i] = i;
        sort(id + 1, id + n + 1, [&](int i, int j){return dist[i] > dist[j];});
        for (int i = 1; i <= n; i++) {
            int u = id[i];
            for (int k = h[u]; k != -1; k = ne[k]) {
                int j = e[k];
                if (dist[u] > dist[j]) dp[j] = (dp[j] + dp[u]) % MOD;
            }
        }  
        return dp[n];      
    }
};