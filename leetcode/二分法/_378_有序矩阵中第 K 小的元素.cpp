#include<vector>
using namespace std;
// https://leetcode.cn/problems/kth-smallest-element-in-a-sorted-matrix/description/
class Solution {
private:
bool check (vector<vector<int>>& matrix, int mid, int n, int k) {
    int i = n - 1, j = 0;
    int num = 0;
    while (i >= 0 && j < n) {
        if (matrix[i][j] <= mid) num += i + 1, j++;
        else i--;    
    }
    return num >= k;
}
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n-1][n-1];
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (check(matrix, mid, n, k)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};