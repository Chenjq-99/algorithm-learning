#include<vector>
#include<unordered_map>
using namespace std;
// https://leetcode.cn/problems/count-nice-pairs-in-an-array/
class Solution {
    typedef long long LL;
    static const int MOD = 1e9 + 7;
    int rev(int x) {
        int t = 0;
        while (x) t = t * 10 + x % 10, x /= 10;
        return t;
    }
public:
    int countNicePairs(vector<int>& nums) {
        LL res = 0;
        unordered_map<int, int> mp;
        for (auto &x : nums) mp[x - rev(x)]++;
        for (auto &p : mp) res = (res + (LL)p.second * (p.second - 1) / 2) % MOD;
        return res;
    }
};