#include<vector>
#include<math.h>
using namespace std;
// https://leetcode.cn/problems/closest-dessert-cost/description/
class Solution {
private:
    int tar;
    int res = -1;
    void backtracking (vector<int>& t, int i, int sum) {
        if (i == t.size()) {
            if (res == -1 || abs(sum - tar) < abs(res - tar) || (abs(sum - tar) == abs(res - tar) && sum < res)) {
                res = sum;
            }
            return;
        }
        for (int j = 0; j <= 2; j++) {
            sum += j * t[i];
            backtracking(t, i + 1, sum);
            sum -= j * t[i];
        } 
    }
public:
    int closestCost(vector<int>& b, vector<int>& t, int target) {
        tar = target;
        for (int i = 0; i < b.size(); i++) {
            backtracking(t, 0, b[i]);
        }
        return res;
    } 
};

