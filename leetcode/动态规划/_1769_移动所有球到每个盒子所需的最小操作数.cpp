#include<vector>
#include<string>
using namespace std;
// https://leetcode.cn/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size(), m = 0;
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            if(boxes[i] == '1') {
                dp[0] += i;
                m++;
            }
        }
        int cnt = m - (boxes[0] == '1');
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i - 1] + (m - 2 * cnt);
            if (boxes[i] == '1') cnt--;
        }
        return dp;
    }
};