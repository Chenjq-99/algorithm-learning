#include<vector>
using namespace std;
// https://leetcode.cn/problems/cycle-length-queries-in-a-tree/
class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>> &queries) {
        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; ++i) {
            int res = 1, a = queries[i][0], b = queries[i][1];
            while (a != b) {
                a > b ? a /= 2 : b /= 2;
                ++res;
            }
            ans[i] = res;
        }
        return ans;
    }
};
