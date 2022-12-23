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
    这道题与最小滑动窗口有点像
    对于searchForlower 只要mid >= target 就让 r = mid -1  (拼命向左压缩) 
    对于searchForluper 只要mid <= target 就让 l = mid +1  (拼命向右压缩) 
    需要注意的几点：
    1.对于uper，当找到nums[mid] == target, l又进行了一次l = mid +1，最后uper要-1;
    2.当nums[lower] != target  时说明数组中没有target;
    3.如果数组中没有target且数组中元素都小于target，那么lower会加到nums.size(),造成索引超出范围;
#endif

// 2022年11月19日
// 参考灵神 https://www.bilibili.com/video/BV1AP41137w7/?spm_id_from=333.788&vd_source=ea4c7f6cec7348f957fc3bf2130b63e2
class Solution
{
private:
    // 要求 nums 是非递减的， 即 nums[i] <= nums[i+1]
    // 返回最小满足 nums[i] >= target 的 i
    // 如果不存在返回nums数组长度
    int lower_bound(const vector<int> nums, int target)
    {
        int l = 0, r = nums.size() - 1; // 在闭区间[l, r]内寻找
        while (l <= r)
        {
            int m = (l + r) / 2; // 如果爆int可以 l + (l - r) / 2
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
    // 对于求第一个 nums[i] > target 就是求 ≥ (target + 1)
    // 对于求最后一个 nums[i] < target 就是求 (≥ target) - 1
    // 对于求最后一个 nums[i] ≤ target 就是求 ≥ (target + 1) - 1
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