// https://leetcode.cn/problems/the-number-of-beautiful-subsets/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int beautifulSubsets(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        vector<bool> vis(1001);
        function<void(int)> dfs = [&](int u)
        {
            if (u == int(nums.size()))
            {
                ++ans;
                return;
            }
            if (!(nums[u] >= k && vis[nums[u] - k]))
            {
                vis[nums[u]] = true;
                dfs(u + 1);
                vis[nums[u]] = false;
            }
            dfs(u + 1);
        };
        dfs(0);
        return ans - 1;
    }
};