#include<vector>
using namespace std;
// https://leetcode.cn/problems/form-array-by-concatenating-subarrays-of-another-array/
class Solution {
private:
    int kmp(vector<int>& p, vector<int>& s) {
        if (p.size() > s.size()) return -1;
        // 求解next数组
        int n = s.size(), m = p.size();
        p.insert(p.begin(), 0);
        s.insert(s.begin(), 0);
        vector<int> ne(m + 1, 0);
        for (int i = 2, j = 0; i <= m; i ++ )
        {
            while (j && p[i] != p[j + 1]) j = ne[j];
            if (p[i] == p[j + 1]) j ++ ;
            ne[i] = j;
        }

        // 匹配
        for (int i = 1, j = 0; i <= n; i ++ )
        {
            while (j && s[i] != p[j + 1]) j = ne[j];
            if (s[i] == p[j + 1]) j ++ ;
            if (j == m)
            {
                j = ne[j];
                // 匹配成功后的逻辑
                return i;
            }
        }
        return -1;
    }
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = groups.size();
        int t = 0;
        for (int i = 0; i < n; i++) {
            vector<int> s(nums.begin() + t , nums.end());
            t = kmp(groups[i], s);
            if (t == -1) return false;
        }
        return true;
    }
};