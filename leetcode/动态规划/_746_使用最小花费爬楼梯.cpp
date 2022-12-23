#include<vector>
using namespace std;

// https://leetcode.cn/problems/min-cost-climbing-stairs/description/
class Solution {
public:
#if 0
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i -2]);
        }
        return dp[n];
    }
#endif
    // 优化： 只维护两个变量
    int minCostClimbingStairs(vector<int>& cost) {
        int first = 0;
        int second = 0;
        for (int i = 2; i <= cost.size(); i++) {
            int cur = min(first + cost[i - 2], second + cost[i - 1]);
            first = second;
            second = cur;
        }
        return second;
    }
};