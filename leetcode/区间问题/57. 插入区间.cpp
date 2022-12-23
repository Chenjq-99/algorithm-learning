#include<vector>
using namespace std;
// https://leetcode.cn/problems/insert-interval/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
        int n = a.size();
        if (n == 0) return {b};
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (a[mid][0] <= b[0]) l = mid;
            else r = mid - 1;
        }
        // [0,l)照抄
        vector<vector<int>> res(a.begin(),a.begin() + l);
        // 判断第l个区间和新区间的关系
        // 保证a[l][0] <= b[0]
        if (a[l][0] > b[0]) swap(a[l], b);
        int left = b[0], right = b[1];
        if (b[0] <= a[l][1]) { // 有交集，合并
            left = a[l][0];
            right = max(a[l][1],b[1]);
        } else { // 没有交集， 把第l个区间插入结果
            res.push_back(a[l]);
        }
        int idx = l + 1;
        while (idx < n && a[idx][0] <= right) { // 有交集
            right = max(right, a[idx][1]);
            idx++;
        }
        res.push_back(vector<int>{left, right});
        // [idx,end)照抄
        res.insert(res.end(), a.begin() + idx, a.end());
        return res;
    }
};