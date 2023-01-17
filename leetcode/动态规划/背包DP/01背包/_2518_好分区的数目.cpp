#include<vector>
#include<cstring>
#include<numeric>
using namespace std;
// https://leetcode.cn/problems/number-of-great-partitions/
class Solution {
    const int MOD = 1e9 + 7;
public:
    int countPartitions(vector<int>& nums, int k) {
        if (accumulate(nums.begin(), nums.end(), 0L) < k * 2) return 0;
        int n = nums.size();
        // ���з�������ĿΪ 2 ^ n
        // �÷�������Ŀ = ���з�������Ŀ - ����������Ŀ
        // ����������Ԫ�غ�С��k�ķ���
        // v1 : [] [1] [2] [3] [1,2]
        // v2 : [] [1] [2] [3] [1,2]
        // ��ô����ͱ��Ԫ�غ�С��k�����������Ŀ=>01����
        // Ԫ�غ�С��k�����������Ŀ = Ԫ�غ͵���k-1�����������Ŀ + Ԫ�غ͵���k-2�����������Ŀ ����
        int f[k], res = 1;
        memset(f, 0, sizeof f);
        f[0] = 1; // û�п�ѡ��Ԫ�أ�ʲô����ѡҲ��Ϊ��f[0]��һ�����
        for (int x : nums) {
            res = res * 2 % MOD;
            for (int j = k - 1; j >= x; j--) {
                f[j] = (f[j] + f[j - x]) % MOD;
            }
        }
        for (int x : f) {
            res = (res - x * 2 % MOD + MOD) % MOD;
        }
        return res;
    }
};