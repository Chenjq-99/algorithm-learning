#include<vector>
#include<numeric>
using namespace std;
// https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        // sum = [l, r)
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < x) return -1;
        int res = 0x3f3f3f3f;
        for (int r = n, l = 0; r <= l + n; r++) {
            while (l < n && sum > x) sum -= nums[l++];
            if (sum == x) res = min(res, r - l);
            sum += nums[r % n];
        }
        return res > n ? -1 : res;
    }
};