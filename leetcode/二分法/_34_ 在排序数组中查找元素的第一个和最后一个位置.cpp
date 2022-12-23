#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return vector<int>{-1, -1};
        int lower = searthForlower(nums, target);
        int uper = searthForuper(nums, target) - 1;
        if (lower == nums.size() || nums[lower] != target)
            return vector<int>{-1, -1};
        return vector<int>{lower, uper};
    }

private:
    int searthForuper(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int k = (l + r) / 2;
            if (nums[k] <= target)
            {
                l = k + 1;
            }
            else
            {
                r = k - 1;
            }
        }
        return l;
    }
    int searthForlower(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int k = (l + r) / 2;
            if (nums[k] >= target)
            {
                r = k - 1;
            }
            else
            {
                l = k + 1;
            }
        }
        return l;
    }
};

#if 0
    ���������С���������е���
    ����searchForlower ֻҪmid >= target ���� r = mid -1  (ƴ������ѹ��) 
    ����searchForluper ֻҪmid <= target ���� l = mid +1  (ƴ������ѹ��) 
    ��Ҫע��ļ��㣺
    1.����uper�����ҵ�nums[mid] == target, l�ֽ�����һ��l = mid +1�����uperҪ-1;
    2.��nums[lower] != target  ʱ˵��������û��target;
    3.���������û��target��������Ԫ�ض�С��target����ôlower��ӵ�nums.size(),�������������Χ;
#endif

// 2022��11��19��
// �ο����� https://www.bilibili.com/video/BV1AP41137w7/?spm_id_from=333.788&vd_source=ea4c7f6cec7348f957fc3bf2130b63e2
class Solution
{
private:
    // Ҫ�� nums �Ƿǵݼ��ģ� �� nums[i] <= nums[i+1]
    // ������С���� nums[i] >= target �� i
    // ��������ڷ���nums���鳤��
    int lower_bound(const vector<int> nums, int target)
    {
        int l = 0, r = nums.size() - 1; // �ڱ�����[l, r]��Ѱ��
        while (l <= r)
        {
            int m = (l + r) / 2; // �����int���� l + (l - r) / 2
            if (nums[m] < target)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return l;
    }
    // note:
    // �������һ�� nums[i] > target ������ �� (target + 1)
    // ���������һ�� nums[i] < target ������ (�� target) - 1
    // ���������һ�� nums[i] �� target ������ �� (target + 1) - 1
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int begin = lower_bound(nums, target);
        if (begin == nums.size() || nums[begin] != target)
            return vector<int>{-1, -1};
        int end = lower_bound(nums, target + 1) - 1;
        return vector<int>{begin, end};
    }
};