#include<vector>
#include<string>
#include<algorithm>
using namespace std;
// https://leetcode.cn/problems/longest-string-chain/description/
class Solution {
    bool check(string &s1, string &s2) {
        if (s2.size() != s1.size() + 1) return false;
        int cnt = 0;
        for (int i = 0, j = 0; i < s1.size();) {
            if (s1[i] == s2[j]) i++, j++;
            else cnt++, j++;
            if (cnt > 1) return false;
        }
        return true;
    } 
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size(), ans = 0;
        sort(words.begin(), words.end(), [&](auto &s1, auto &s2){return s1.size() < s2.size();});
        vector<int> f(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (check(words[j], words[i])) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
            ans = max(ans, f[i]);
        }
        return ans;
    }
};