#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
private:
    typedef pair<int, int> PII; 
    static const int N = 10010;
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int dist[N];
    bool st[N];
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        memset(dist, 0x3f, sizeof dist);
        memset(st, false, sizeof st);
        dist[0] = 0;
        priority_queue<PII, vector<PII>, greater<>> heap;
        heap.emplace(0, 0);
        auto id2XY = [&](int id){return PII{id / n, id % n};};
        auto XY2id = [&](int x, int y){return x * n + y;};
        while (heap.size()) {
            auto t = heap.top();
            heap.pop();
            int ver = t.second, w = t.first;
            if (st[ver]) continue;
            st[ver] = true;
            auto [x, y] = id2XY(ver);
            for (int i = 0; i < 4; i++) {
                int nx = x + dirs[i][0], ny = y + dirs[i][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int nver = XY2id(nx, ny);
                    int nw = abs(heights[x][y] - heights[nx][ny]);
                    dist[nver] = min(dist[nver], max(w, nw));
                    heap.emplace(dist[nver], nver);
                }
            }
        }
        return dist[n * m - 1];
    }
};