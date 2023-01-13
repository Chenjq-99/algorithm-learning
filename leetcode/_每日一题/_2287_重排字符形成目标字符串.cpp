#include<string>
using namespace std;
// https://leetcode.cn/problems/rearrange-characters-to-make-target-string/
class Solution {
public:
    int rearrangeCharacters(string s, string t) {
        int h1[26] = {0}, h2[26] = {0};
        for (auto &c : s) h1[c - 'a']++;
        for (auto &c : t) h2[c - 'a']++;
        int res = 0x3f3f3f3f;
        for (auto &c : t) res = min(res, h1[c - 'a'] / h2[c - 'a']);
        return res;
    }
};