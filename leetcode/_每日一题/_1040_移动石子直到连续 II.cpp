#include<vector>
#include<algorithm>
using namespace std;
// https://leetcode.cn/problems/moving-stones-until-consecutive-ii/
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size();
        int max_moves = 0, min_moves = n;
        int m = (stones[n - 1] - stones[0] + 1) - n;
        max_moves = m - min(stones[1] - stones[0] - 1, stones[n - 1] - stones[n - 2] - 1);
        for (int r = 0, l = 0; r < n; r++) {
            while(stones[r] - stones[l] + 1 > n) l++;
            m = r - l + 1;
            int t;
            if (m == n - 1 && stones[r] - stones[l] == r - l) t = 2;
            else t = n - m;
            min_moves = min(min_moves, t);
        }
        return {min_moves, max_moves};
    }
};