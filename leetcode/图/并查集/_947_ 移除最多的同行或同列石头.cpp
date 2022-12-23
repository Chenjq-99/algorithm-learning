#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

// https://leetcode.cn/problems/most-stones-removed-with-same-row-or-column/
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
    int removeStones(vector<vector<int>>& stones) {
        UnionFind uf(stones.size());
        for(int i = 0; i < stones.size(); i++){
            for(int j = i + 1; j < stones.size(); j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    uf.unite(i,j);
                }
            }
        }
        return stones.size() - uf.setCount;
    }
};