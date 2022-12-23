#include<vector>
#include<unordered_map>
using namespace std;

// https://leetcode.cn/problems/minimum-size-subarray-sum/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = INT32_MAX;
        int sum = 0;
        int left = 0;
        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];
            while(sum >= target){
                len = min(len, right - left + 1);
                sum -= nums[left++];
            }
            
        }
        return len == INT32_MAX ? 0 : len;
    }
};