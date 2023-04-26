#include<vector>
using namespace std;
// https://leetcode.cn/problems/maximum-sum-of-two-non-overlapping-subarrays/description/
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int l1, int l2) {
        int n = nums.size();
        vector<int> s(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
        int mxl = 0, ans = 0, mxr = 0;
        for (int i = n - l2 + 1; i > 0; i--) b[i] = mxl = max(mxl, s[i + l2 - 1] - s[i - 1]);
        for (int i = 1; i + l1 - 1 <= n; i++) {
            if (i >= l2 + 1) mxr = max(mxr, s[i - 1] - s[i - l2 - 1]);
            int t = s[i + l1 - 1] - s[i - 1];
            ans = max(ans, mxr + t);
            if (i + l1 <= n) ans = max(ans, t + b[i + l1]);
        }
        return ans;
    }
};