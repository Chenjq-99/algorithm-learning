#include<vector>
#include<string>
using namespace std;
// https://leetcode.cn/problems/camelcase-matching
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n = queries.size();
        vector<bool> ans(n);
        for (int i = 0; i < n; i++) {
            int t = 0, flag = 1;
            for (int j = 0; j < queries[i].size(); j++) {
                if (t < pattern.size() && queries[i][j] == pattern[t]) {
                    t++;
                    continue;
                } 
                if (isupper(queries[i][j])) {
                    flag = 0;
                    break;
                }
            }
            ans[i] = flag && t == pattern.size();
        }
        return ans;
    }
};