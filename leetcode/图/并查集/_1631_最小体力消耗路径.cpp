#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

// https://leetcode.cn/problems/path-with-minimum-effort/
class Solution {
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
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<tuple<int,int,int>> edges;
        UnionFind uf(rows * cols);
        auto getIndex = [&](int x, int y){
            return x * cols + y;
        };
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(i + 1 < rows){
                    edges.emplace_back(getIndex(i,j),getIndex(i+1,j),abs(heights[i][j] - heights[i+1][j]));
                }
                if(j + 1 < cols){
                    edges.emplace_back(getIndex(i,j),getIndex(i,j+1),abs(heights[i][j] - heights[i][j+1]));
                }
            }
        }
        sort(edges.begin(), edges.end(), [](auto e1, auto e2){
            auto [x1,y1,v1] = e1;
            auto [x2,y2,v2] = e2;
            return v1 < v2;
        });
        int res = 0;
        for(auto& [x,y,v] : edges){
            if(uf.same(0, rows * cols -1)) break;
            res = v;
            uf.unite(x,y);
        }
        return res;
    }
};