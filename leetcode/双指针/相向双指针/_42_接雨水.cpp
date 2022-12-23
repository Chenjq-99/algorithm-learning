#include<vector>
using namespace std;

// https://leetcode.cn/problems/trapping-rain-water/
class Solution {
public:
    // ����ǰ׺���ֵ�ͺ�׺���ֵ
    #if 0
    int trap(vector<int>& height) {
        int n = height.size();
        int pre_max[n];
        pre_max[0] = height[0];
        for (int i = 1; i < n; i++) {
            pre_max[i] = max(height[i], pre_max[i-1]);
        }
        int suf_max[n];
        suf_max[n-1] = height[n-1];
        for (int i = n-2; i >= 0; i--) {
            suf_max[i] = max(height[i], suf_max[i+1]);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += min(pre_max[i], suf_max[i]) - height[i];
        }
        return res;
    }
    #endif

    // �Ż� ʹ������ָ��
    // ������������¼ǰ׺���ֵһ�������׺���ֵ��
    // �������ֵֻ�����󲻻��С����ǰ׺���ֵС�ں�׺���ֵʱ����ôǰ׺���ֵһ���������Ԫ��С�ı�,��ߵĵ�Ԫ����ȷ��
    // ͬ����׺���ֵС��ǰ׺���ֵʱ����ô��׺���ֵһ���������Ԫ��С�ıߣ��ұߵĵ�Ԫ����ȷ��
    int trap(vector<int>& height) {
        int n = height.size();
        int pre_max = height[0];
        int suf_max = height[n-1];
        int left = 0;
        int right = n - 1;
        int res = 0;
        while(left <= right) {
            pre_max = max(pre_max, height[left]);
            suf_max = max(suf_max, height[right]);
            if (pre_max < suf_max) {
                res += pre_max - height[left++];
            } else {
                res += suf_max - height[right--];
            }
        }
        return res;
    }
};