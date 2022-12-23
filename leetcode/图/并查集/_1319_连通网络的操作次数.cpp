#include<iostream>
#include<vector>
#include<numeric>
#include<unordered_map>
using namespace std;

// https://leetcode.cn/problems/number-of-operations-to-make-network-connected/
// 并查集模板
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
        if (px == py) {
            return;
        }
        if (size[px] < size[py]) {
            swap(px, py);
        }
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

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }

        UnionFind uf(n);
        for (const auto& conn: connections) {
            uf.unite(conn[0], conn[1]);
        }

        return uf.setCount - 1;
    }
};