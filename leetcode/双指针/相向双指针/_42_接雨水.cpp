#include<vector>
using namespace std;

// https://leetcode.cn/problems/trapping-rain-water/
class Solution {
public:
    // 利用前缀最大值和后缀最大值
    #if 0
    int trap(vector<int>& height) {
        int n = height.size();
        int pre_max[n];
        pre_max[0] = height[0];
        for (int i = 1; i < n; i++) {
            pre_max[i] = max(height[i], pre_max[i-1]);
        }
        int suf_max[n];
        suf_max[n-1] = height[n-1];
        for (int i = n-2; i >= 0; i--) {
            suf_max[i] = max(height[i], suf_max[i+1]);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += min(pre_max[i], suf_max[i]) - height[i];
        }
        return res;
    }
    #endif

    // 优化 使用两个指针
    // 用两个变量记录前缀最大值一个代表后缀最大值，
    // 由于最大值只能增大不会减小，当前缀最大值小于后缀最大值时，那么前缀最大值一定是这个单元最小的边,左边的单元可以确定
    // 同理当后缀最大值小于前缀最大值时，那么后缀最大值一定是这个单元最小的边，右边的单元可以确定
    int trap(vector<int>& height) {
        int n = height.size();
        int pre_max = height[0];
        int suf_max = height[n-1];
        int left = 0;
        int right = n - 1;
        int res = 0;
        while(left <= right) {
            pre_max = max(pre_max, height[left]);
            suf_max = max(suf_max, height[right]);
            if (pre_max < suf_max) {
                res += pre_max - height[left++];
            } else {
                res += suf_max - height[right--];
            }
        }
        return res;
    }
};