#include<vector>
#include<math.h>
using namespace std;
// https://leetcode.cn/problems/soup-servings/description/
class Solution {
public:
#if 0
// 动态规划
    double soupServings(int n) {
        n = ceil((double) n / 25);
        if (n >= 179) {
            return 1.0;
        }
        vector<vector<double>> dp(n + 1, vector<double>(n + 1));
        dp[0][0] = 0.5;
        for (int i = 1; i <= n; i++) {
            dp[0][i] = 1.0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = 0.25 * (dp[max(0, i-4)][j] + dp[max(0, i-3)][max(0,j-1)] 
                           + dp[max(0,i-2)][max(0,j-2)] + dp[max(0,i-1)][max(0,j-3)]);
            }
        }
        return dp[n][n];
    }
#endif

// 记忆化搜索
    double soupServings(int n) {
        n = ceil((double) n / 25);
        if (n >= 179) {
            return 1.0;
        }
        memo = vector<vector<double>>(n + 1, vector<double>(n + 1));
        return dfs(n,n);
        
    }
    double dfs (int a, int b) {
        if (a <= 0 && b <= 0) {
            return 0.5;
        } else if (a <= 0) {
            return 1.0;
        } else if (b <= 0) {
            return 0.0;
        }
        if (memo[a][b] > 0) {
            return memo[a][b];
        }
        memo[a][b] = 0.25 * (dfs(a - 4, b) + dfs(a - 3, b - 1) + dfs(a - 2, b - 2) + dfs(a - 1, b - 3));
        return memo[a][b];
    }
private:
    vector<vector<double>> memo;
};