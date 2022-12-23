#include<vector>
using namespace std;
// https://leetcode.cn/problems/search-a-2d-matrix/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int u = 0, d = m - 1;
        while (u < d) {
            int mid = u + d + 1>> 1;
            if(matrix[mid][0] <= target) u = mid;
            else d = mid - 1;
        }
        if (matrix[u][0] > target) return false;
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if(matrix[u][mid] <= target) l = mid;
            else r = mid - 1;
        }
        if (matrix[u][l] != target) return false;
        return true;
    }
};