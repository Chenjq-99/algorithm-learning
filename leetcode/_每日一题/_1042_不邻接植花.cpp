#include<vector>
using namespace std;
// https://leetcode.cn/problems/flower-planting-with-no-adjacent/description/
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> g(n + 1);
        for (auto& path : paths) {
            g[path[0]].push_back(path[1]);
            g[path[1]].push_back(path[0]);
        } 
        vector<int> ans(n);
        for (int i = 1; i <= n; i++) {
            vector<bool> colors(5, false);
            for (auto& j : g[i]) colors[ans[j - 1]] = true;
            for (int j = 1; j <= 4; j++) {
                if (colors[j]) continue;
                ans[i - 1] = j;
            }
        }
        return ans;        
    }
};