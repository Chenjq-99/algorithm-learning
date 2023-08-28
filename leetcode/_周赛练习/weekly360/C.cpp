// https://leetcode.cn/problems/minimum-operations-to-form-subsequence-with-target-sum/
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;


class Solution {
public:
    int lowbit(int x)
    {
        return x & (-x);
    }
    int minOperations(vector<int>& nums, int target) {
        vector<int> cnt(32);
        long long sum = 0;
        for (auto& x : nums)
        {
            int t = __builtin_popcount(lowbit(x) - 1);
            sum += x;
            cnt[t]++;
        }
        if (sum < target) return -1;
        int ans = 0;
        sum = 0;
        for (int i = 0; i <= 30; i++) 
        {
            sum += 1LL * cnt[i] * (1 << i);
            if (target & (1 << i)) 
                if (cnt[i] || sum >= (1 << i)) sum -= 1 << i;
                else 
                    for (int j = i + 1; j <= 30; j++) 
                        if (cnt[j]) 
                        {
                            ans += j - i;
                            cnt[j]--;
                            int k = ((1 << j) - 1) - ((1 << i) - 1);
                            sum += k & target;
                            i = j - 1;
                            break;
                        }
        }        
        return ans;
    }
};