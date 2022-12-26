#include<vector>
#include<numeric>
#include<cstring>
using namespace std;
// https://leetcode.cn/problems/target-sum/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // ������Ԫ�صĺ�Ϊsum�����У��ŵĲ��ֺ�Ϊp����-�ŵĲ��ֺ�Ϊsum - p
        // p - (sum - p) = tar => p = (tar + sum) / 2;
        // ��tar + sum = x
        int x = accumulate(nums.begin(), nums.end(), target);
        // ��� x < 0 ���� x Ϊ���� ���Ҳ���p
        if (x < 0 || x & 1) return 0;
        // �����ɣ����������Һ�Ϊx/2�����������Ŀ
        x /= 2;
        int f[x + 1];
        memset(f, 0, sizeof f);
        f[0] = 1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = x; j >= nums[i]; j--) {
                f[j] += f[j - nums[i]];
            }
        }
        return f[x];
    }
};