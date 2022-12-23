#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

// https://leetcode.cn/problems/satisfiability-of-equality-equations/
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
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf(26);
        for(string equation : equations){
            if(equation[1] == '=') uf.unite(equation[0]-'a',equation[3]-'a');
        }
        for(string equation : equations){
            if(equation[1] == '!' && uf.same(equation[0]-'a',equation[3]-'a')) return false;
        }
        return true;
    }
};