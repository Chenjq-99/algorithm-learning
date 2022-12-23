#include<vector>
#include<string.h>
using namespace std;
// https://www.baidu.com/s?tn=68018901_27_oem_dg&ie=utf-8&wd=memset%E5%A4%B4%E6%96%87%E4%BB%B6
class Solution {
public:
#if 0
    // ģ��
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
    // һάdp
    double champagneTower(int poured, int query_row, int query_glass) {
        // ��Ϊ��1�б��Ϊ1����ôһ����Ҫ����query_row + 1��
        // ��query_row + 1�У��� query_row + 1 �����ӣ����Ϊ 1 �� query_row + 2
        // �����ĺô��Ƿ���һ������ı��ӣ�����Ҫ�����жϱ߽����
        double dp[query_row + 2]; 
        memset(dp, 0, sizeof(dp));
        dp[1] = poured;
        for (int i = 2; i <= query_row + 1; i++) {
            // ����ÿһ�ű�����Ҫ�����������Ϊ���ڵ�j�����ӵļ�����������һ�е�j��j-1�ı��ӣ��������ȸ���j-1
            for (int j = i; j >= 1; j--) {
                dp[j] = (max(dp[j] - 1, 0.) + max(dp[j - 1] - 1, 0.)) / 2;
            }
        }
        return min(dp[query_glass+1],1.0);
    }
};