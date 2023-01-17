#include<vector>
#include<cstring>
using namespace std;
// https://leetcode.cn/problems/increment-submatrices-by-one/
class Solution {
    static const int N = 510;
    int b[N][N];
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        memset(b, 0, sizeof b);
        vector<vector<int>> res (n, vector<int>(n));
        for (int i = 0; i < queries.size(); i++) {
            int x1 = queries[i][0] + 1, y1 = queries[i][1] + 1;
            int x2 = queries[i][2] + 1, y2 = queries[i][3] + 1;
            b[x1][y1] += 1, b[x1][y2 + 1] -= 1, b[x2 + 1][y1] -= 1, b[x2 + 1][y2 + 1] += 1;
        }
        for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            res[i- 1][j - 1] = (b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1]);
        }
        return res;
    }
};