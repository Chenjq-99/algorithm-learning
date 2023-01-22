#include<string>
using namespace std;
// https://leetcode.cn/problems/append-characters-to-string-to-make-subsequence/description/
class Solution {
public:
    int appendCharacters(string s, string t) {
        int idx1 = 0;
        int idx2 = 0;
        while (idx1 <= s.length() && idx2 <= t.length()) {
            if (s[idx1] == t[idx2]) {
                idx2++;
            }
            idx1++;
        }
        return max((int)t.length() - idx2, 0);
    }
};