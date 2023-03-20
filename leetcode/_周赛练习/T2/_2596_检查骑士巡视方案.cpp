// https://leetcode.cn/problems/check-knight-tour-configuration/
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dirs = {{-2,-1},{-1,-2},{1,-2},{2,-1},{-2,1},{-1,2},{1,2},{2,1}};
        int cur_x = 0, cur_y = 0, f = 0;
        bool find = false;
        while (f < n * n - 1) {
            find = false;
            for (auto &d : dirs) {
                int x = cur_x + d[0], y = cur_y + d[1];
                if (x >= 0 && x < n && y >= 0 && y < n) {
                    if (grid[x][y] == f + 1) {
                        cur_x = x, cur_y = y, f += 1;
                        find = true;
                        break;
                        
                    } 
                }
            }
            if (!find) return false;
        }
        // cout << f << endl;
        return f == n * n -1 ? true : false;
    }
};