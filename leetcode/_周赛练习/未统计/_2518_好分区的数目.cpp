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
        // 所有分区的数目为 2 ^ n
        // 好分区的数目 = 所有分区的数目 - 坏分区的数目
        // 坏分区就是元素和小于k的分区
        // v1 : [] [1] [2] [3] [1,2]
        // v2 : [] [1] [2] [3] [1,2]
        // 那么问题就变成元素和小于k的子区间的数目=>01背包
        // 元素和小于k的子区间的数目 = 元素和等于k-1的子区间的数目 + 元素和等于k-2的子区间的数目 ……
        int f[k], res = 1;
        memset(f, 0, sizeof f);
        f[0] = 1; // 没有可选的元素，什么都不选也认为是f[0]的一种情况
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