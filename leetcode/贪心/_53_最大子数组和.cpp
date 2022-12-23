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
            if(preSum > 0) preSum += nums[i]; //̰��,���preSum�ܴ�������ͼ���preSum
            else preSum = nums[i];//���preSum���ܴ������������preSum����¯��
            maxSum = max(maxSum,preSum);
        }
        return maxSum;
    }
};