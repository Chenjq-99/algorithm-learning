#include<vector>
#include<string>
using namespace std;

// https://leetcode.cn/problems/maximum-subarray/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int preSum = 0;
        int maxSum = INT32_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(preSum > 0) preSum += nums[i]; //贪心,如果preSum能带来增益就加上preSum
            else preSum = nums[i];//如果preSum不能带来增益就抛弃preSum另起炉灶
            maxSum = max(maxSum,preSum);
        }
        return maxSum;
    }
};