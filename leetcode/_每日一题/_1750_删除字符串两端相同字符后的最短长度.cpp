#include<string>
using namespace std;

// https://leetcode.cn/problems/minimum-length-of-string-after-deleting-similar-ends/
class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        while (l < r && s[l] == s[r]) {
            char c = s[l];
            while (l < n && s[l] == c) l++;
            while (r >= 0 && s[r] == c) r--;
        }
        if (l > r) return 0;
        return r - l + 1;
    }
};