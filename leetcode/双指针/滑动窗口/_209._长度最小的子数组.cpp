#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// https://leetcode.cn/problems/minimum-size-subarray-sum/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = INT32_MAX;
        int sum = 0;
        int i = 0;
        for(int j = 0; j < nums.size(); j++){
            sum += nums[j];
            while(sum >= target){
                len = len < j - i + 1 ? len : j -i +1;
                sum -= nums[i++];
            }
            
        }
        return len == INT32_MAX ? 0 : len;
    }
};