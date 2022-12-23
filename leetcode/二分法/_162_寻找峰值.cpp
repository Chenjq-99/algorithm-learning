#include<vector>
using namespace std;

// https://leetcode.cn/problems/find-peak-element/description/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 2;
        while (left - 1< right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[mid+1]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};