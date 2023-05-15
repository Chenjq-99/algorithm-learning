#include<bits/stdc++.h>
using namespace std;
// https://leetcode.cn/problems/flip-columns-for-maximum-number-of-equal-rows/
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
        int ans = 0, n = matrix[0].size();
        unordered_map<string, int> cnt;
        for (auto &row: matrix) {
            string r(n, 0);
            for (int j = 0; j < n; ++j)
                r[j] = row[j] ^ row[0]; // 翻转第一个数为 1 的行
            ans = max(ans, ++cnt[r]);
        }
        return ans;
    }
};
