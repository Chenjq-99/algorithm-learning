#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// https://leetcode.cn/problems/longest-increasing-subsequence/
class Solution {
public:
    // 动态规划 时间复杂度O(n^20)
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        int maxRes = 1;
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            maxRes = max(maxRes,dp[i]);
        }
        return maxRes;
    }
    // 二分搜索  + 纸牌游戏 时间复杂度O(nlogn)
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> top; // 牌顶数组
        // 遍历所有牌
        for (auto& num : nums) {
            auto it = upper_bound(top.begin(), top.end(), num, [](int num, int ele){return num <= ele;});
            if (it == top.end()) {
                top.push_back(num);
            } else {
                *it = num;
            }
        }
        return top.size();
    }
};