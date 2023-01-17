#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class Solution {
public:
    double largestSumOfAverages1(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<double>> dp(k, vector(n, 0.));
        for (int i = 0; i < n; i++) {
            dp[0][i] = (double) accumulate(nums.begin(),nums.begin() + i + 1, 0) / (i + 1);
        }
        for (int i = 1; i < k; i++) {
            for (int j = i; j < n; j++) {
                for (int m = i - 1; m < j; m++) {
                    double tmp = (double) accumulate(nums.begin() + m + 1, nums.begin() + j + 1, 0) / (j - m);
                    dp[i][j] = max(dp[i][j], dp[i-1][m] + tmp);
                }
            }
        }
        return dp[k-1][n-1];
    }
// 利用滚动数组优化
    double largestSumOfAverages2(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> dp(n, 0.);
        for (int i = 0; i < n; i++) {
            dp[i] = (double) accumulate(nums.begin(),nums.begin() + i + 1, 0) / (i + 1);
        }
        for (int i = 1; i < k; i++) {
            for (int j = n - 1; j >= i; j--) {
                for (int m = i - 1; m < j; m++) {
                    double tmp = (double) accumulate(nums.begin() + m + 1, nums.begin() + j + 1, 0) / (j - m);
                    dp[j] = max(dp[j], dp[m] + tmp);
                }
            }
        }
        return dp[n-1];
    }
// 利用前缀和优化
double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> dp(n, 0.);
        vector<double> prefix(n, 0.);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++){
            prefix[i]  = prefix[i-1] + nums[i];
        }
        for (int i = 0; i < n; i++) {
            dp[i] = prefix[i] / (i + 1);
        }
        for (int i = 1; i < k; i++) {
            for (int j = n - 1; j >= i; j--) {
                for (int m = i - 1; m < j; m++) {
                    double tmp = (prefix[j] - prefix[m]) / (j - m);
                    dp[j] = max(dp[j], dp[m] + tmp);
                }
            }
        }
        return dp[n-1];
    }
};