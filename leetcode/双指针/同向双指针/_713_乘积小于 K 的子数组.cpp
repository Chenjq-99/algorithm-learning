#include<vector>
using namespace std;

// https://leetcode.cn/problems/subarray-product-less-than-k/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int n = nums.size();
        int l = 0;
        int product = 1;
        int res = 0;
        for(int r = 0; r < n; r++) {
            product *= nums[r];
            while(product >= k) {
                product /= nums[l++];
            }
            res += r - l + 1;
        }
        return res;
    }
};