#include<vector>
#include<cstring>
using namespace std;
// https://leetcode.cn/problems/house-robber-ii
class Solution {
    int _rob(vector<int> nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int f[n];
        memset(f, 0, sizeof f);
        f[0] = nums[0], f[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) 
            f[i] = max(f[i - 1], f[i - 2] + nums[i]);
        return f[n - 1];
    }
public:
    int rob(vector<int>& nums) {
        // ���һ����β����͵ _ 2 3 _
        // ���������͵��һ�� _ 2 3 1 
        // ���������͵�����һ�� 1 2 3 _
        // ��������ǰ������һ��
        if (nums.size() == 1) return nums[0];
        return max(_rob(vector<int>(nums.begin() + 1, nums.end())), _rob(vector<int>(nums.begin(), nums.end() - 1)));
    }
};