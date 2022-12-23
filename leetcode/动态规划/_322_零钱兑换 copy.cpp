#include<vector>
using namespace std;

// https://leetcode.cn/problems/unique-paths/description/
class Solution {
public:
#if 0
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) dp[i][0] = 1;
        for (int j = 0; j < n; j++) dp[0][j] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
#endif
    // 优化 使用滚动数组
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(j == 0) dp[j] = 1;
                else {
                    dp[j] = dp[j] + dp[j-1]; // dp[j-1]其实是dp[i][j-1] dp[j]是dp[i-1][j]
                }
            }
        }
        return dp[n-1];
    }
};