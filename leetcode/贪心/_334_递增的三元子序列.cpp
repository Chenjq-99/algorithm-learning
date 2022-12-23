#include<vector>
#include<iostream>
using namespace std;

// https://leetcode.cn/problems/increasing-triplet-subsequence/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        int a = nums[0], b = INT32_MAX;
        for (int i = 1; i < n; i++) {
            if (nums[i] > b) return true;
            else if (nums[i] > a) b = nums[i];
            else a = nums[i];
        }
        return false;
    }
};