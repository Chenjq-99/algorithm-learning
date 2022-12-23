#include<vector>
#include<set>
using namespace std;
// https://leetcode.cn/problems/longest-square-streak-in-an-array/
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for (auto x : s) {
            int cnt = 0;
            while (s.find(x) != s.end()) {
                cnt++;
                if (x <= 316) x *= x;
                else break;
            }
            ans = max(ans, cnt);
        }
        return ans > 1 ? ans : -1;
    }
};