// https://leetcode.cn/problems/fibonacci-number/description/
class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// 优化：只维护两个变量
class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        int first = 0;
        int second = 1;
        for(int i = 0; i < n-1; i++)
        {
            int sum = first + second;
            first = second;
            second = sum;
        }
        return second;
    }
};