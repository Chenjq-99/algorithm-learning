#include<vector>
#include<string.h>
using namespace std;
// https://www.baidu.com/s?tn=68018901_27_oem_dg&ie=utf-8&wd=memset%E5%A4%B4%E6%96%87%E4%BB%B6
class Solution {
public:
#if 0
    // 模拟
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> curRow = {(double)poured};
        for (int i = 1; i <= query_row; i++) {
            vector<double> nextRow(i + 1,0.0);
            for (int j = 0; j < curRow.size(); j++) {
                if (curRow[j] > 1) {
                    nextRow[j] += (curRow[j] - 1) / 2;
                    nextRow[j+1] += (curRow[j] - 1) / 2;
                }
            }
            curRow = nextRow;
        }
        return min(1.0,curRow[query_glass]);
    }
#endif
    // 一维dp
    double champagneTower(int poured, int query_row, int query_glass) {
        // 认为第1行编号为1，那么一共需要计算query_row + 1行
        // 第query_row + 1行，有 query_row + 1 个杯子，编号为 1 到 query_row + 2
        // 这样的好处是放了一排虚拟的杯子，不需要额外判断边界情况
        double dp[query_row + 2]; 
        memset(dp, 0, sizeof(dp));
        dp[1] = poured;
        for (int i = 2; i <= query_row + 1; i++) {
            // 对于每一排杯子需要倒序遍历，因为对于第j个杯子的计算依赖于上一行的j和j-1的杯子，不能先先更新j-1
            for (int j = i; j >= 1; j--) {
                dp[j] = (max(dp[j] - 1, 0.) + max(dp[j - 1] - 1, 0.)) / 2;
            }
        }
        return min(dp[query_glass+1],1.0);
    }
};