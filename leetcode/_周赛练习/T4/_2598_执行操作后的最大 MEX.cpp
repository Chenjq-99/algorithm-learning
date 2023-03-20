// https://leetcode.cn/problems/smallest-missing-non-negative-integer-after-operations/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        bool vis[n + 1];
        int cnt[value];
        memset(vis, false, sizeof vis);
        memset(cnt, 0, sizeof cnt);
        for (auto &x : nums) {
            int t = (x % value + value) % value;
            int y = cnt[t] * value + t;
            if (y < n) vis[y] = true;
            cnt[t]++;
        }
        int ans = 0;
        while (vis[ans]) ans++;
        return ans;        
    }
};