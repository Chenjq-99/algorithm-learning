#include<vector>
#include<numeric>
#include<math.h>
using namespace std;
// https://leetcode.cn/problems/minimum-adjacent-swaps-for-k-consecutive-ones/
class Solution {
public:
    int minMoves(vector<int> &nums, int k) {
        vector<int> p;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i]) p.push_back(i - p.size());
        int m = p.size(), s[m + 1];
        s[0] = 0;
        partial_sum(p.begin(), p.end(), s + 1); // p ��ǰ׺��
        int ans = INT_MAX;
        for (int i = 0; i <= m - k; ++i) // p[i] �� p[i+k-1] ���������� p[i+k/2] �ľ���֮�ͣ�ȡ��Сֵ
            ans = min(ans, s[i] + s[i + k] - s[i + k / 2] * 2 - p[i + k / 2] * (k % 2));
        return ans;
    }
};