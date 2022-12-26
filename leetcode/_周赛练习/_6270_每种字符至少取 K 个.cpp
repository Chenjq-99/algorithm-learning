#include<string>
#include<unordered_map>
using namespace std;
// https://leetcode.cn/problems/take-k-of-each-character-from-left-and-right/
class Solution {
public:
    int takeCharacters(string s, int k) {
        if (k == 0) return 0;
        int l = 0;
        int n = s.size();
        int res = INT32_MAX;
        unordered_map<char, int> map;
        for (int i = 0; i < n; i++) map[s[i]]++;
        auto check = [&](){return map['a'] >= k && map['b'] >= k && map['c'] >= k;};
        if (!check()) return -1;
        while (check() && l < n) {
            map[s[l]]--;
            res = min(res, n - l);
            l++;
        }
        for (int r = 0; r < n && r - l + 1 <= 0; r++) {
            map[s[r]]++;
            while (check() && l <= n) {
                map[s[l % n]]--;
                res = min(res, n + r - l + 1);
                l++;
            }
        }
        return res == INT32_MAX ? -1 : res;
    }
};