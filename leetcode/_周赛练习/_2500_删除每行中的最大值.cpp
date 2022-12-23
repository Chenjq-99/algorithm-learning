#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
// https://leetcode.cn/problems/delete-greatest-value-in-each-row/
class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) sort(grid[i].begin(), grid[i].end(), greater<>());
        for (int i = 0; i < n; i++) {
            int maxele = 0;
            for (int j = 0; j < m; j++) {
                maxele = max(maxele, grid[j][i]);
            }
            ans += maxele;
        }
        return ans;
    }
};