#include<vector>
using namespace std;
// https://leetcode.cn/problems/gas-station/description/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for (int i = 0; i < n; i++) {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (curSum < 0) { // 当curSum < 0 则 0 - i 都不能作为起点，因为一定走不出 i，此时至少要从i+1开始
                start = i + 1;
                curSum = 0;
            }
        }
        if(totalSum < 0) return -1;
        return start;
    }
};      