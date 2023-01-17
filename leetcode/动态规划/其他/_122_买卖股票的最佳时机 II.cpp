#include<vector>
#include<string>
using namespace std;

// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i][1]��i����е�����ֽ�
        // dp[i][0]��i����й�Ʊ�������ֽ�
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] -= prices[0]; // �ֹ�Ʊ
        for (int i = 1; i < n; i++) {
            // ��i��ֹ�Ʊ��ʣ����ֽ� = max(��i-1��ֹ�Ʊ��ʣ�ֽ�, ��i-1����ֽ�-���i��Ĺ�Ʊ)
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            // ��i���������ֽ� = max(��i-1����е�����ֽ𣬵�i-1����й�Ʊ������ֽ�+��i��������Ʊ)
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]); 
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};