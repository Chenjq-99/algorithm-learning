#include<algorithm>
#include<vector>
using namespace std;

// https://leetcode.cn/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i = 0; i < n - 2; i++) { //给j和k指针留两个位置
        
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            // 优化
            if(nums[i] + nums[i + 1] + nums[i + 2] > 0) break;
            if(nums[i] + nums[n - 2] + nums[n - 1] < 0) continue;

            int j = i + 1;
            int k = n - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum > 0) k--;
                else if(sum < 0) j++;
                else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while(j < k && nums[j] == nums[j - 1]) j++;
                    k--;
                    while(k > j && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return res;
    }
};