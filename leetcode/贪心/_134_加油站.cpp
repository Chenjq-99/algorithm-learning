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
            if (curSum < 0) { // ��curSum < 0 �� 0 - i ��������Ϊ��㣬��Ϊһ���߲��� i����ʱ����Ҫ��i+1��ʼ
                start = i + 1;
                curSum = 0;
            }
        }
        if(totalSum < 0) return -1;
        return start;
    }
};      