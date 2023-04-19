#include<vector>
using namespace std;
// https://leetcode.cn/problems/partition-array-for-maximum-sum/
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> f(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int mx = arr[i - 1];
            for (int j = i; j >= 1 && i - j + 1 <= k; j--) {
                mx = max(mx, arr[j - 1]), f[i] = max(f[i], f[j - 1] + mx * (i - j + 1));
            }
        }
        return f[n];
    }
};