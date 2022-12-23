#include<vector>
#include<algorithm>
using namespace std;
// https://leetcode.cn/problems/missing-number/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] > mid) r = mid;
            else l = mid + 1;
        }
        return nums[l] == l ? l + 1 : l;
    }
};