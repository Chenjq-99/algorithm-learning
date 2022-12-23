#include<vector>
using namespace std;
// https://leetcode.cn/problems/path-with-maximum-gold/description/
class Solution {
private:
    int maxGold = 0;
    int m, n;
    int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                int gold = 0;
                if(grid[i][j] != 0) {
                    backtracking(grid, i, j, gold);
                }
            }
        }
        return maxGold;
    }
    void backtracking(vector<vector<int>>& grid, int i , int j, int gold) {
        if(i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == 0) {
            return;
        }
        int temp = grid[i][j];
        gold += temp;
        maxGold = max(maxGold, gold);
        grid[i][j] = 0;
        for(auto d : direction) {
            backtracking(grid, i + d[0], j + d[1], gold);
        }
        grid[i][j] = temp;
    }

};