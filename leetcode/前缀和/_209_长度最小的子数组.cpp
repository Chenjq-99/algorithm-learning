#include<vector>
using namespace std;
// https://leetcode.cn/problems/minimum-size-subarray-sum/description/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int s[n + 1], res = n + 1;
        s[0] = 0;
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + nums[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            if (s[i] >= target) {
                // 1 - i 找一个最大j 满足s[i] - s[j - 1] >= target，即s[j - 1] <= s[i] - target
                // 二分查找
                int l = 1, r = i;
                while (l < r) {
                    int mid = l + r + 1 >> 1;
                    if (s[mid - 1] <= s[i] - target) l = mid;
                    else r = mid - 1;
                }
                // 判断j = l是否合法
                if (s[l - 1] <= s[i] - target) res = min(res, i - l + 1);
            }
        }
        return res == n + 1 ? 0 : res;
    }
};