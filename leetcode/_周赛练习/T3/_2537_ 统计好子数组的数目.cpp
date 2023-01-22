#include<unordered_map>
#include<vector>
using namespace std;
// https://leetcode.cn/problems/count-the-number-of-good-subarrays/
typedef long long LL;
class Solution {
    LL get(int x) {
        return (LL) x * (x - 1) / 2;
    }
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        LL cnt = 0, res = 0;
        for (int r = 0, l = 0; r < n; r++) {
            int a = ++mp[nums[r]];
            cnt += (get(a) - get(a - 1));
            res += l;
            while (cnt >= k) {
                res += 1;
                int a = --mp[nums[l]];
                cnt -= (get(a + 1) - get(a));
                l++;
            }
        }
        return res;
    }
};
