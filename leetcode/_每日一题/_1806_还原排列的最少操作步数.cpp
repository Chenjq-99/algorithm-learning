// https://leetcode.cn/problems/minimum-number-of-operations-to-reinitialize-a-permutation/
class Solution {
    int qmi(int a, int k, int p) {
        int res = 1;
        while (k) {
            if (k & 1) res = res * a % p;
            a = a * a % p;
            k >>= 1;
        }
        return res;
    }
public:
    int reinitializePermutation(int n) {
        if (n == 2) return 1;
        for (int k = 1; ; k++) {
            if (qmi(2, k, n - 1) == 1) return k;
        }
        return 0;
    }
};