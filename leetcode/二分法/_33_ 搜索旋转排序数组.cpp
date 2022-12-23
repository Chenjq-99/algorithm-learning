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
    ������ص������ж�mid�����ı�������ģ�
    ���nums[l] <= nums[mid]˵����ʱ���������ģ���ʱ���ж�target�ڲ�����ߣ�����ھͰ�r���Ƶ�mid-1,������ھͰ�l�Ƶ�mid+1
    ���nums[l] > nums[mid] ˵����ʱ�ұ�������ģ���ʱ���ж�target�ڲ����ұߣ�����ھͰ�l���Ƶ�mid+1,������ھͰ�r�Ƶ�mid-1
#endif