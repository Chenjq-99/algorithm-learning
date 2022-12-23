#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        // 当子数组是奇数时: 左侧大于 + 右侧大于 = 左侧小于 + 右侧小于
        //                  左侧大于 - 左侧小于 = 右侧小于 - 右侧大于
        // 当子数组是偶数时: 左侧大于 + 右侧大于 - 1 = 左侧小于 + 右侧小于
        //                  左侧大于 - 左侧小于 - 1 = 右侧小于 - 右侧大于 
        // 这样就变成了类似两数之和的问题，用hashMap记录右边情况，再遍历左边，统计答案
        // 注意只有元素k，也算一种情况，初始化cnt[0] = 1
        int idx = distance(nums.begin(), find(nums.begin(), nums.end(), k));
        unordered_map<int,int> cnt;
        cnt[0] = 1;
        int n = 0;
        for (int i = idx + 1; i < nums.size(); i++) {
            n += (nums[i] < k) ? 1 : -1;
            cnt[n]++;
        }
        n = 0;
        int res = cnt[0] + cnt[-1];
        for (int i = idx -1; i >= 0; i--) {
            n += (nums[i] > k) ? 1 : -1;
            res += cnt[n] + cnt[n-1];
        }
        return res;
    }
};
