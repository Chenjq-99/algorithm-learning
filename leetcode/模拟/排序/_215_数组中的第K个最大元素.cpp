#include<vector>
using namespace std;
// https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
// 基于快排的快选
class Solution {
private:
    int quick_select(vector<int>& nums, int l, int r, int k) {
        if (l >= r) return nums[l];
        int x = nums[(l + r) >> 1], i = l - 1, j = r + 1;
        while (i < j) {
            do i++; while(nums[i] < x);
            do j--; while(nums[j] > x);
            if (i < j) swap(nums[i], nums[j]);
        }
        if (j >= k) return quick_select(nums, l, j, k);
        else return quick_select(nums, j + 1, r, k);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quick_select(nums, 0, nums.size() - 1, nums.size()-k);
    }
};