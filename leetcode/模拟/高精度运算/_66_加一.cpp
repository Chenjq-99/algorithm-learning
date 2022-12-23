#include<vector>
#include<algorithm>
using namespace std;
// https://leetcode.cn/problems/plus-one/description/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        digits[0] += 1;
        int t = 0;
        for (int i = 0; i < digits.size(); i++) {
            t += digits[i];
            digits[i] = t % 10;
            t /= 10;
            if (t == 0) break;
        }
        if (t) digits.push_back(t);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};