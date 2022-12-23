#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

// https://leetcode.cn/problems/network-delay-time/
class Solution {
private:
    // 朴素Dijkstra
    static const int N = 110;
    int g[N][N], dist[N];
    bool st[N];
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        memset(g, 0x3f, sizeof g);
        for (auto& t : times) {
            int u = t[0], v = t[1], w = t[2];
            g[u][v] = w;
        }
        memset(dist, 0x3f, sizeof dist);
        dist[k] = 0;
        for (int i = 1; i <= n; i++) {
            int t = -1; // 找距离最小的结点
            for (int j = 1; j <= n; j++) {
                if (!st[j] && (t == -1 || dist[j] < dist[t])) {
                    t = j;
                }
            }
            st[t] = true;
            for (int j = 1; j <= n; j++) { // 松弛
                dist[j] = min(dist[j], dist[t] + g[t][j]);
            }
        }
        int res = *max_element(dist + 1, dist + n + 1);
        if (res > 0x3f3f3f3f / 2) return -1;
        return res;
    }
};