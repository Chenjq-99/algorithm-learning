#include<vector>
using namespace std;

// https://leetcode.cn/problems/unique-paths-ii/
class Solution {
public:
#if 0
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] != 1) dp[i][0] = 1;
            else break;
        }
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[0][j] != 1) dp[0][j] = 1;
            else break;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
#endif
    // 优化 使用滚动数组
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n, 0);
        // 用第0行初始化
        for (int j = 0; j < n; j++) {
           if (obstacleGrid[0][j] != 1) dp[j] = 1;
            else break;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(obstacleGrid[i][j] == 1) dp[j] = 0;
                else if (j > 0) dp[j] = dp[j] + dp[j-1];
                // 默认当j == 0 时 如果obstacleGrid[i][0]不是障碍物就和上一行保持一致，不需要更改
            }
        }
        return dp[n-1];
    }
};