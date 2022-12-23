#include<vector>
using namespace std;

// https://leetcode.cn/problems/sum-of-all-subset-xor-totals/description/?topicTags=backtracking
class Solution {
private:
    int res = 0;
    void backtracking(int startIdx, vector<int>& nums, int pre) {
        res += pre;
        for(int i = startIdx; i < nums.size(); i++) {
            backtracking(i + 1, nums, pre ^ nums[i]);
        }
    }
public:
    int subsetXORSum(vector<int>& nums) {
        backtracking(0, nums, 0);
        return res;
    }
};