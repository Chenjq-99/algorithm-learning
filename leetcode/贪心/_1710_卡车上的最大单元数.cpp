#include<vector>
#include<algorithm>
using namespace std;

// https://leetcode.cn/problems/maximum-units-on-a-truck/description/
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int res = 0;
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& v1, vector<int>& v2){return v1[1] >= v2[1];});
        for (auto& x : boxTypes) {
            if (x[0] <= truckSize) {
                res += x[0] * x[1];
                truckSize -= x[0];
            } else {
                res += truckSize * x[1];
                return res;
            }
        }
        return res;
    }
};