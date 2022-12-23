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
    // 2022.11.23参考灵神https://www.bilibili.com/video/BV1QK411d76w/?spm_id_from=444.41.list.card_archive.click&vd_source=ea4c7f6cec7348f957fc3bf2130b63e2
    // 每次的nums[mid] 和 最后一个元素比较
    class Solution {
    public:
        int findMin(vector<int>& nums) {
            int left = 0;
            int right = nums.size() - 2;
            while (left - 1 < right) {
                int mid = (left + right) / 2;
                if (nums[mid] < nums.back()) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return nums[left];
        }
    };
#endif