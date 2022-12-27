#include<string>
using namespace std;
// https://leetcode.cn/problems/minimum-moves-to-convert-string/
class Solution {
public:
    int minimumMoves(string s) {
        int n = s.size();
        int cnt = 0, idx = 0;
        while (idx < n) {
            if (s[idx] == 'X') {
                cnt++;
                idx += 2;
            }
            ++idx;
        }
        return cnt;
    }
};