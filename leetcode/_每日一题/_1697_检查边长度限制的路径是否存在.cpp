#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

// https://leetcode.cn/problems/checking-existence-of-edge-length-limited-paths/
class Solution {
private:
    vector<int> p;
    int find (int x) {
        return x == p[x] ? p[x] : p[x] = find(p[x]);
    }
    void unite (int x, int y) {
        int px = find(x), py = find(y);
        if (px != py) {
            p[px] = py;
        }
    }
    bool isSame (int x, int y) {
        return find(x) == find(y);
    }
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& e, vector<vector<int>>& q) {
        int n = e.size(), m = q.size();
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        sort(e.begin(), e.end(), [&](const vector<int>& v1, const vector<int>& v2){
            return v1[2] < v2[2];
        });
        vector<int> idx(m);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int idx1, int idx2) {
            return q[idx1][2] < q[idx2][2];
        });
        vector<bool> ans(m);
        for (int i: idx) {
            int j = 0;
            int x = q[i][0], y = q[i][1], t = q[i][2];
            while (j < n && e[j][2] < t) {
                unite(e[j][0], e[j][1]);
                j++;
            }
            ans[i] = isSame(x, y);
        }
        return ans;
    }
};