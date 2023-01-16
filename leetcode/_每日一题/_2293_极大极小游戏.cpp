#include<vector>
using namespace std;
// https://leetcode.cn/problems/min-max-game/
class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        while (nums.size() > 1) {
            vector<int> newNums(nums.size() / 2);
            for (int i = 0; i < nums.size() / 2; i++) {
                if (i & 1) newNums[i] = max(nums[2 * i], nums[2 * i + 1]);
                else newNums[i] = min(nums[2 * i], nums[2 * i + 1]);
            }
            nums = move(newNums);
        }
        return nums[0];
    }
};