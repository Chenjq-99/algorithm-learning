#include<vector>
using namespace std;
// https://leetcode.cn/problems/range-sum-query-immutable/description/
class NumArray {
private:
    int s[10010];
public:
    NumArray(vector<int>& nums) {
        s[0] = 0;
        for (int i = 1; i <= nums.size(); i++) {
            s[i] = s[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return s[right+1] - s[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */