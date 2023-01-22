#include<vector>
using namespace std;
// https://leetcode.cn/problems/difference-between-element-sum-and-digit-sum-of-an-array/
class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum = 0;
        for (auto &x : nums) {
            sum += x;
            while (x) sum -= x % 10, x /= 10;
        }
        return sum;
    }
};