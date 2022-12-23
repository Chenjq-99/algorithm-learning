#include<vector>
#include<algorithm>
using namespace std;
// https://leetcode.cn/problems/wiggle-subsequence/description/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int curDiff = 0; // ��ǰһ�Բ�ֵ
        int preDiff = 0; // ǰһ�Բ�ֵ
        int result = 1;  // ��¼��ֵ����������Ĭ���������ұ���һ����ֵ
        for (int i = 0; i < nums.size() - 1; i++) {
            curDiff = nums[i + 1] - nums[i];
            // ���ַ�ֵ
            if ((curDiff > 0 && preDiff <= 0) || (preDiff >= 0 && curDiff < 0)) {
                result++;
                preDiff = curDiff;
            }
        }
        return result;
    }
};