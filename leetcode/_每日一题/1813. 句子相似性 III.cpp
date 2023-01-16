#include<vector>
#include<string>
using namespace std;

// https://leetcode.cn/problems/sentence-similarity-iii
class Solution {
    vector<string> spilt(string s) {
        vector<string> res;
        int l = 0, r = 0;
        while (r < s.size()) {
            while(r < s.size() && s[r] != ' ') r++;
            res.push_back(s.substr(l, r - l));
            l = ++r;
        }
        return res;
    }
public:
    bool areSentencesSimilar(string s1, string s2) {
        if (!s1.size() || !s2.size()) return true;
        if (s1.size() < s2.size()) swap(s1, s2);
        vector<string> vs1 = spilt(s1);
        vector<string> vs2 = spilt(s2);
        int n = vs1.size(), m = vs2.size();
        int l = 0, r = m - 1;
        while (l < m && vs2[l] == vs1[l]) l++;
        while (r >= 0 && vs2[r] == vs1[r + n - m]) r--;
        return l > r;
    }
};