#include<vector>
using namespace std;
// https://leetcode.cn/problems/difference-between-ones-and-zeros-in-row-and-column/
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> onesRow(m), onesCol(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                onesRow[i] += grid[i][j];
                onesCol[j] += grid[i][j];
            }
        }
        vector<vector<int>> diff(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                diff[i][j] = 2 * onesRow[i] + 2 * onesCol[j] - m - n;
            }
        }
        return diff;
    }
};