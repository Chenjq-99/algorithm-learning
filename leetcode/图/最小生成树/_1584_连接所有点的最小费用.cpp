#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

// https://leetcode.cn/problems/minimize-hamming-distance-after-swap-operations/
class Solution {
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
class Edge{
public:
    int from;
    int to;
    int weight;
    Edge(int _from, int _to, int _weight)
    : from(_from), to(_to), weight(_weight){}
};
    static bool cmp(Edge& e1, Edge& e2){
        return e1.weight < e2.weight;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<Edge> edges;
        int n = points.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back(Edge(i,j,weight));
            }
        }
        sort(edges.begin(), edges.end(), cmp);
        int count = 0;
        int res = 0;
        UnionFind uf(n);
        for(auto edge : edges){
            if(count == n - 1) break;
            if(uf.same(edge.from,edge.to)) continue;
            uf.unite(edge.from,edge.to);
            res += edge.weight;
            count++;
        }
        return res;        
    }
};