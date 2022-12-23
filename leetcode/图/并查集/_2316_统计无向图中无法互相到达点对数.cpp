#include<vector>
#include<numeric>
using namespace std;

// https://leetcode.cn/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/
class Solution {
private:
class UnionFind {
public:
    vector<int> parent;
    vector<int> size;
    int n;
    int setCount;
    
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
    long long countPairs(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for(auto edge : edges){
            uf.unite(edge[0], edge[1]);
        }
        vector<long long> setSize(n);
        for(int i = 0; i < n; i++){
            setSize[uf.find(i)]++;
        }
        long long res = 0;
        for(int i = 0; i < n; i++){
            if(setSize[i] != 0)
            res += setSize[i] * (n - setSize[i]);
        }
        return res / 2;
    }
};