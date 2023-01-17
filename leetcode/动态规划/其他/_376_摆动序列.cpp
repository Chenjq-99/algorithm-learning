#include<vector>
#include<algorithm>
using namespace std;
// https://leetcode.cn/problems/wiggle-subsequence/description/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int dp[1000][2] = {{1, 1}};
        // ��dp״̬dp[i][0]����ʾ����ǰi��������i������Ϊɽ��İڶ������е������
        // ��dp״̬dp[i][1]����ʾ����ǰi��������i������Ϊɽ�ȵİڶ������е������
        dp[0][0] = dp[0][1] = 1;
        for(int i = 1; i < n; i++) {
            dp[i][0] = dp[i][1] = 1;
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] > nums[i]) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            }

            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i]) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            }
        }
        return max(dp[n - 1][0],dp[n - 1][1]);
    }
};