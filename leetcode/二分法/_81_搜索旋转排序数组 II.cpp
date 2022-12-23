#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() -1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (target == nums[mid]) return true;

            if (nums[l] < nums[mid])
            {
                if (target >= nums[l] && target < nums[mid])
                    r = mid-1;
                else
                    l = mid+1;
            }
            else if (nums[l] > nums[mid])
            {
                if (target > nums[mid] && target <= nums[r])
                    l = mid +1;
                else
                    r = mid -1;
            }
            else{
                l++;
            }
        }
        return false;
    }
};

#if 0
    ����������33�����������е�Ԫ�����ظ��ģ���nums[l] == nums[mid]ʱl++ȥ��
#endif