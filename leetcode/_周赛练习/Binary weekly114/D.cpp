#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> grid(n);
        for (auto& e : edges) {
            grid[e[0]].push_back(e[1]);
            grid[e[1]].push_back(e[0]);
        }
        function<pair<int, int>(int, int)> dfs = [&](int x, int fa) {
            int cnt = 0, sum = values[x];
            for (auto& y : grid[x]) {
                if (y == fa) continue;
                auto p = dfs(y, x);
                cnt += p.first, sum += p.second;
            }
            if (sum % k == 0) cnt += 1, sum = 0;
            return pair<int, int>{cnt, sum};
        };
        return dfs(0, -1).first;
    }
};