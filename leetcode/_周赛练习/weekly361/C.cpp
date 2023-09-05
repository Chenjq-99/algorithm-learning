// https://leetcode.cn/problems/count-of-interesting-subarrays/submissions/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;


class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        vector<int> s(n + 1);
        unordered_map<int, int> mp;
        mp[0]++;
        for (int i = 1; i <= n; i++)
        {
            s[i] = s[i - 1] + (nums[i - 1] % modulo == k);
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += mp[(s[i] - k) % modulo];
            mp[s[i] % modulo]++;
        }
        return ans;
    }
};