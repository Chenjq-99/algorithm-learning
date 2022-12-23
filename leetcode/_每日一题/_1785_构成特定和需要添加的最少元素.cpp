#include<vector>
#include<math.h>
using namespace std;
// https://leetcode.cn/problems/minimum-elements-to-add-to-form-a-given-sum/
class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = 0;
        for (auto x : nums) {
            sum += x;
        }
        long long diff = abs(sum - goal);
        return (diff + limit - 1) / limit;
    }
};
  