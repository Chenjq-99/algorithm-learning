#include<vector>
using namespace std;
// https://leetcode.cn/problems/sort-colors/
class Solution {
private:
    void quickSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int x = nums[(l + r) >> 1], i = l - 1, j = r + 1;
        while (i < j) {
            do i++; while (nums[i] < x);
            do j--; while (nums[j] > x);
            if (i < j) swap(nums[i], nums[j]);
        }
        quickSort(nums, l, j);
        quickSort(nums, j + 1, r);
    }
public:
    void sortColors(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
    }
};