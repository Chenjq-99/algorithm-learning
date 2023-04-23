#include<vector>
using namespace std;
// https://leetcode.cn/problems/filling-bookcase-shelves/description/
class Solution {
public:
    int minHeightShelves(vector<vector<int>> &books, int shelf_width) {
        int n = books.size(), f[n + 1];
        f[0] = 0; 
        for (int i = 0; i < n; ++i) {
            f[i + 1] = 0x3f3f3f3f;
            int max_h = 0, left_w = shelf_width;
            for (int j = i; j >= 0; --j) {
                left_w -= books[j][0];
                if (left_w < 0) break; 
                max_h = max(max_h, books[j][1]); 
                f[i + 1] = min(f[i + 1], f[j] + max_h);
            }
        };
        return f[n]; 
    }
};
