#include<vector>
using namespace std;
// https://leetcode.cn/problems/minimum-score-of-a-path-between-two-cities/description/
class Solution {
private:
    int p[100010], minCost = 0x3f3f3f3f;
    int find (int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        for (int i = 1; i <= n; i++) {
            p[i] = i;
        }
        for (auto& road : roads) {
            int px = find(road[0]);
            int py = find(road[1]);
            p[py] = px;
        }
        for (auto& road : roads) {
            if (find(1) == find(road[0])) minCost = min(minCost, road[2]);
        }
        return minCost;
    }
};