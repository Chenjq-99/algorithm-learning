#include<vector>
using namespace std;
// https://leetcode.cn/problems/maximum-count-of-positive-integer-and-negative-integer/
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int s1 = 0, s2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) s1++;
            else if (nums[i] > 0) s2++;
        }
        return max(s1, s2);
    }
};