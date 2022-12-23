#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

// https://leetcode.cn/problems/check-if-there-is-a-valid-path-in-a-grid/
class Solution {
private:
    class UnionFind {
    public:
        vector<int> parent;
        vector<int> size;
        int n;
        int setCount; // 当前连通分量数目
        
    public:
        UnionFind(int _n): n(_n), setCount(_n), parent(_n), size(_n, 1) {
            iota(parent.begin(), parent.end(), 0);
        }
        
        int find(int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        }
        
        void unite(int x, int y) {
            int px = find(x);
            int py = find(y);
            if (px == py) return;
            if (size[px] < size[py]) swap(px, py);
            parent[py] = px;
            size[px] += size[py];
            --setCount;
            return;
        }
        
        bool same(int x, int y) {
            int px = find(x);
            int py = find(y);
            return px == py;
        }
    };
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        UnionFind uf(m * n);
        auto getId = [&] (int x, int y) {
            return x * n + y;
        };
        auto detectL = [&] (int x, int y) {
            if (y - 1 >= 0 && (grid[x][y - 1] == 4 || grid[x][y - 1] == 6 || grid[x][y - 1] == 1)) {
                uf.unite(getId(x, y), getId(x, y - 1));
            }
        };

        auto detectR = [&] (int x, int y) {
            if (y + 1 < n && (grid[x][y + 1] == 3 || grid[x][y + 1] == 5 || grid[x][y + 1] == 1)) {
                uf.unite(getId(x, y), getId(x, y + 1));
            }
        };

        auto detectU = [&] (int x, int y) {
            if (x - 1 >= 0 && (grid[x - 1][y] == 3 || grid[x - 1][y] == 4 || grid[x - 1][y] == 2)) {
                uf.unite(getId(x, y), getId(x - 1, y));
            }
        };

        auto detectD = [&] (int x, int y) {
            if (x + 1 < m && (grid[x + 1][y] == 5 || grid[x + 1][y] == 6 || grid[x + 1][y] == 2)) {
                uf.unite(getId(x, y), getId(x + 1, y));
            }
        };
        
        auto handler = [&] (int x, int y) {
            switch (grid[x][y]) {
                case 1: {
                    detectL(x, y); detectR(x, y);
                } break;
                case 2: {
                    detectU(x, y); detectD(x, y);
                } break;
                case 3: {
                    detectL(x, y); detectD(x, y);
                } break;
                case 4: {
                    detectR(x, y); detectD(x, y);
                } break;
                case 5: {
                    detectL(x, y); detectU(x, y);
                } break;
                case 6: {
                    detectR(x, y); detectU(x, y);
                }
            }
        };
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                handler(i, j);
            }
        }
        return uf.same(0,m * n - 1);
    }
};