#include<vector>
using namespace std;

// https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/description/
class Solution {
int n;
vector<int> tmp;
int merge_sort (vector<int>& nums, int l, int r) {
    if (l >= r) return 0;
    int mid = l + r >> 1, i = l, j = mid + 1, k = 0;
    int cnt = merge_sort(nums, l, mid) + merge_sort(nums, mid + 1, r);
    while (i <= mid && j <= r) {
        if (nums[i] <= nums[j]) tmp[k++] = nums[i++];
        else {
            cnt += mid - i + 1;
            tmp[k++] = nums[j++];
        }
    }
    while (i <= mid) tmp[k++] = nums[i++];
    while (j <= r) tmp[k++] = nums[j++];
     for (int i = l, k = 0; i <= r; i++, k++) nums[i] = tmp[k];
    return cnt;  
}
public:
    int reversePairs(vector<int>& nums) {
        n = nums.size();
        tmp.resize(n);
        return merge_sort(nums, 0, n - 1);
    }
};