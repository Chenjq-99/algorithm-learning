#include<vector>
#include<cstring>
using namespace std;
// https://leetcode.cn/problems/cheapest-flights-within-k-stops/
class Solution {
private:
    static const int N = 110, M = N * (N - 1) / 2;
    struct Edge{
        int a, b, w;
    } edges[M];
    int dist[N], backup[N];
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m = flights.size();
        for (int i = 0; i < m; i++) {
            int a = flights[i][0], b = flights[i][1], w = flights[i][2];
            edges[i] = {a, b, w};
        }
        memset(dist, 0x3f, sizeof dist);
        dist[src] = 0;
        for (int i = 0; i < k + 1; i++) {
            memcpy(backup, dist, sizeof dist);
            for (int j = 0; j < m; j++) {
                int a = edges[j].a, b = edges[j].b, w = edges[j].w;
                dist[b] = min(dist[b], backup[a] + w);
            }
        }
        if (dist[dst] > 0x3f3f3f3f / 2) return -1;
        return dist[dst];
    }
};