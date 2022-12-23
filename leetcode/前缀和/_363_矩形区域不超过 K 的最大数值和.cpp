#include<vector>
#include<set>
using namespace std;
// https://leetcode.cn/problems/max-sum-of-rectangle-no-larger-than-k/
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        // ¶þÎ¬Ç°×ººÍ
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> s(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i ++) {
            for (int j = 1; j <= n; j++) {
                s[i][j] = s[i][j - 1] + s[i - 1][j] + matrix[i - 1][j - 1] - s[i - 1][j - 1];
            }
        }
        int ans = INT_MIN;
        for (int u = 1; u <= m; u++) {
            for (int d = u; d <= m; d++) {
                set<int> st;
                st.emplace(0);
                for (int r = 1;  r <= n; r++) {
                    int right = s[d][r] - s[u - 1][r];
                    auto left = st.lower_bound(right - k);
                    if (left != st.end()) {
                        int sum = right - *left;
                        ans = max(ans, sum);
                    }
                    st.emplace(right);
                }
            }
        }
        return ans;
    }
};