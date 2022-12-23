#include<vector>
#include<string>
using namespace std;

// https://leetcode.cn/problems/maximum-subarray/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int maxRes = dp[0];
        for(int i = 1; i < nums.size(); i++){
            dp[i] = max(dp[i-1] + nums[i],nums[i]);
            maxRes = max(maxRes,dp[i]);
        }
        return maxRes;
    }
};