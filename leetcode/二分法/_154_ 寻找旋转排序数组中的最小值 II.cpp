#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int res = INT32_MAX;
        int l = 0;
        int r = nums.size()-1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(nums[l] < nums[mid]){
                res = res < nums[l] ? res : nums[l];
                l = mid + 1;
            }else if(nums[l] > nums[mid]){
                res = res < nums[mid] ? res : nums[mid];
                r = mid - 1;
            }else{
                res = res < nums[l] ? res : nums[l];
                l++;
            }    
        }
        return res;
    }
};

#if 0
    这道题和33题和81题思路一样
#endif