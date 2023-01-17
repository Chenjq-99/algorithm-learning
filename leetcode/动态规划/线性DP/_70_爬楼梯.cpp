// https://leetcode.cn/problems/fibonacci-number/description/
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        int dp[n+1];
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i -2];
        }
        return dp[n];
    }
};

// 优化：只维护两个变量
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        int first = 1;
        int second = 2;
        for(int i = 3; i <= n; i++){
            second = first + second;
            first = second -first;
        }
        return second;
    }
};