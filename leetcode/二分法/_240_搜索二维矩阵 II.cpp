#include<vector>
using namespace std;
// https://leetcode.cn/problems/search-a-2d-matrix-ii/
class Solution {
public:
// 二分查找
    bool searchMatrix1(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            int l = 0, r = n - 1;
            while (l < r) {
                int mid = l + r >> 1;
                if (matrix[i][mid] >= target) r = mid;
                else l = mid + 1;
            }
            if (matrix[i][l] == target) return true;
        }
        return false;
    }
// Z形查找，从右上角开始查，每次排除一行或者一列
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n - 1;
        while (x < m && y >= 0) {
            if (matrix[x][y] < target) x++;
            else if (matrix[x][y] > target) y--;
            else return true;
        }
        return false;
    }
};