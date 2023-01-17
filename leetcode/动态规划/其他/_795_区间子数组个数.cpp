#include<vector>
using namespace std;

// https://leetcode.cn/problems/number-of-subarrays-with-bounded-maximum/description/
class Solution {
public:
// ��������
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int res = 0, l = 0, record = 0;
        bool flag = 0;
        for (int r = 0; r < nums.size(); r++) { // while �˻����� if
            if (nums[r] > right) {
                l = r + 1;
                flag = 0;
            }
            // ���½��
            if (nums[r] <= right && nums[r] >= left) {
                record = r;
                flag = 1;
            }
            if (flag) res += record - l + 1;
        }
        return res;
    }
// ��̬�滮
    int numSubarrayBoundedMax1(vector<int>& nums, int left, int right) {
        int n = nums.size();
        int dp[n+1];
        int flag = 0;
        dp[0] = 0;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (nums[i - 1] > right) {
                flag = i;
                dp[i] = 0;
            } else if (nums[i - 1] < left) {
                dp[i] = dp[i-1];
            } else {
                dp[i] = i - flag;
            }
            res += dp[i];
        }
        return res;
    }
    // �Ż���ֻ��¼dp[i-1]
    int numSubarrayBoundedMax2(vector<int>& nums, int left, int right) {
        int n = nums.size();
        int flag = 0;
        int record = 0;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (nums[i - 1] > right) {
                flag = i;
                record = 0;
            } else if (nums[i - 1] <= right && nums[i - 1] >= left) {
                record = i - flag;
            }
            res += record;
        }
        return res;
    }
};