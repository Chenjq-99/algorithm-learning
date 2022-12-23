#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
// https://leetcode.cn/problems/find-right-interval/
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> res(n);
        int id[n];
        iota(id, id + n, 0);
        sort(id, id + n, [&](int i, int j){return intervals[i][0] < intervals[j][0];});
        for (int i = 0; i < n; i++) {
            int tar = intervals[id[i]][1];
            int l = i, r = n - 1;
            while (l < r) {
                int mid = l + r >> 1;
                if (intervals[id[mid]][0] >= tar) r = mid;
                else l = mid + 1;
            }
            if (l < n && intervals[id[l]][0] >= tar) res[id[i]] = id[l];
            else res[id[i]] = -1;
        }
        return res;
    }
};