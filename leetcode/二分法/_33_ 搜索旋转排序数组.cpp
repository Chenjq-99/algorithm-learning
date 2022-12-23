#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() -1;
        
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (target == nums[mid]) return mid;

            if (nums[l] <= nums[mid])
            {
                if (target >= nums[l] && target < nums[mid])
                    r = mid-1;
                else
                    l = mid+1;
            }
            else
            {
                if (target > nums[mid] && target <= nums[r])
                    l = mid +1;
                else
                    r = mid -1;
            }
        }
        return -1;
    }
};

#if 0
    这道题重点在与判断mid左右哪边是有序的，
    如果nums[l] <= nums[mid]说明此时左边是有序的，这时候判断target在不在左边，如果在就把r左移到mid-1,如果不在就把l移到mid+1
    如果nums[l] > nums[mid] 说明此时右边是有序的，这时候判断target在不在右边，如果在就把l左移到mid+1,如果不在就把r移到mid-1
#endif