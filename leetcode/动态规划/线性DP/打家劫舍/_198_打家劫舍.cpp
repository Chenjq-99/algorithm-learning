#include<vector>
#include<cstring>
using namespace std;
// https://leetcode.cn/problems/house-robber/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int f[n];
        memset(f, 0, sizeof f);
        f[0] = nums[0], f[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) 
            f[i] = max(f[i - 1], f[i - 2] + nums[i]);
        return f[n - 1];
    }
};