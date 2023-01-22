#include<vector>
#include<string>
using namespace std;
// https://leetcode.cn/problems/shortest-distance-to-target-string-in-a-circular-array/
class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int res = INT32_MAX;
        for (int i = 0; i < n; i++) {
            if (words[(i + startIndex) % n] == target) {
                res = min(res, min(i, n - i));
            }
        }
        return res == INT32_MAX ? -1 : res;
    }
};