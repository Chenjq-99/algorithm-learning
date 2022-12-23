#include<algorithm>
using namespace std;
// https://leetcode.cn/problems/maximum-number-of-balls-in-a-box/description/
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int record[46] = {0};
        for (int i = lowLimit; i <= highLimit; i++) {
            int num = i;
            int n = 0;
            while (num > 0) {
                n += num % 10;
                num /= 10;
            }
            record[n]++;
        }
        // ��������������Ļ�Ӧ����begin,end ��������ָ�����ͷָ��-ͷָ��+�����С
        return *(max_element(record,record + 46));
    }
};