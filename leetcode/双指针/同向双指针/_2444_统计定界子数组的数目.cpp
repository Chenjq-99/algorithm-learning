#include<vector>
using namespace std;
// https://leetcode.cn/problems/count-subarrays-with-fixed-bounds/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0, l = 0, record1 = 0, record2 = 0;
        bool flag1 = 0, flag2 = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] > maxK || nums[r] < minK) {
                l = r + 1;
                flag1 = flag2 = 0;
            }
            if (nums[r] == minK) {
                record1 = r;
                flag1 = 1;
            }
            if (nums[r] == maxK) {
                record2 = r;
                flag2 = 1;
            }
            if (flag1 && flag2) res += min(record1, record2) - l + 1;
        }
        return res;

    }
};