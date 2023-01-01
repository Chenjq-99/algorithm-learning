#include<string>
using namespace std;
// https://leetcode.cn/problems/first-letter-to-appear-twice/
class Solution {
public:
    char repeatedCharacter(string s) {
        int h[26] = {0};
        for (auto& c : s) {
            if (h[c - 'a'] == 1) return c;
            h[c - 'a']++;
        }
        return ' ';
    }
};