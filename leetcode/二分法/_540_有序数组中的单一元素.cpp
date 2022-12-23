#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums){
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(checkSingle(nums,mid)) return nums[mid];
            if(nums[mid] == nums[mid-1]){
                if(mid%2 == 0) r = mid - 2;
                else l = mid + 1;
            }else{
                if(mid%2 == 0) l = mid + 2;
                else r = mid - 1;
            }
        }
        return 0;
    }
private:
    bool checkSingle(vector<int>& nums, int index){ // 辅助函数 用于监测一个元素是否为单一元素
        if(nums.size() == 1) return true;
        if(index == 0) return nums[index] != nums[index+1];
        if(index == nums.size() - 1) return nums[index] != nums[index-1];
        return nums[index] != nums[index-1] && nums[index] != nums[index+1];
    }
};

#if 0
    这道题是常规的二分法+如何判断l r移动方向
    当nums[mid]的值不是single时
        如果nums[mid] == nums[mid+1], 即mid和他后面的元素值相等，此时
            若mid是偶数，那么他前面有偶数个元素，正好能配对，那么前边是正常的，mid和mid+1配对，l直接跳到mid+2；
            若mid是奇数，那么他前面有奇数个元素，不能配对， 那么前面不正常，r直接跳到mid-1;
        nums[mid] == nums[mid-1]的时候同理
#endif